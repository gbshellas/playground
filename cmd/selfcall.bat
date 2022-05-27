@echo off

rem echo %~f0

if "%1" NEQ "execute123" (    
	echo inside recurtion batch
    call selfcall execute123 
    goto :EOF
)

echo end of main batch

