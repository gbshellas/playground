   #define STATUS_CHECK_TIMEOUT      500   // Milliseconds

   DWORD      dwRes;
   DWORD      dwCommEvent;
   DWORD      dwStoredFlags;
   BOOL      fWaitingOnStat = FALSE;
   OVERLAPPED osStatus = {0};

   dwStoredFlags = EV_BREAK | EV_CTS | EV_DSR | EV_ERR | EV_RING |\
                  EV_RLSD | EV_RXCHAR | EV_RXFLAG | EV_TXEMPTY ;
   if (!SetCommMask(comHandle, dwStoredFlags))
      // error setting communications mask; abort
      return 0;

   osStatus.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
   if (osStatus.hEvent == NULL)
      // error creating event; abort
      return 0;

   for ( ; ; ) {
      // Issue a status event check if one hasn't been issued already.
      if (!fWaitingOnStat) {
         if (!WaitCommEvent(hComm, &dwCommEvent, &osStatus)) {
            if (GetLastError() == ERROR_IO_PENDING)
               bWaitingOnStatusHandle = TRUE;
            else
               // error in WaitCommEvent; abort
               break;
         }
         else
            // WaitCommEvent returned immediately.
            // Deal with status event as appropriate.
            ReportStatusEvent(dwCommEvent); 
      }

      // Check on overlapped operation.
      if (fWaitingOnStat) {
         // Wait a little while for an event to occur.
         dwRes = WaitForSingleObject(osStatus.hEvent, STATUS_CHECK_TIMEOUT);
         switch(dwRes)
         {
             // Event occurred.
             case WAIT_OBJECT_0: 
                 if (!GetOverlappedResult(hComm, &osStatus, &dwOvRes, FALSE))
                    // An error occurred in the overlapped operation;
                    // call GetLastError to find out what it was
                    // and abort if it is fatal.
                 else
                    // Status event is stored in the event flag
                    // specified in the original WaitCommEvent call.
                    // Deal with the status event as appropriate.
                    ReportStatusEvent(dwCommEvent);

                 // Set fWaitingOnStat flag to indicate that a new
                 // WaitCommEvent is to be issued.
                 fWaitingOnStat = FALSE;
                 break;

             case WAIT_TIMEOUT:
                 // Operation isn't complete yet. fWaitingOnStatusHandle flag 
                 // isn't changed since I'll loop back around and I don't want
                 // to issue another WaitCommEvent until the first one finishes.
                 //
                 // This is a good time to do some background work.
                DoBackgroundWork();
                 break;                       

             default:
                 // Error in the WaitForSingleObject; abort
                 // This indicates a problem with the OVERLAPPED structure's
                 // event handle.
                CloseHandle(osStatus.hEvent);
                return 0;
         }
      }
   }

   CloseHandle(osStatus.hEvent);