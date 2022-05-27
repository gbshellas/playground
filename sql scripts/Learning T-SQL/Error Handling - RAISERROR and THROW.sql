
-- alter database testdb1 set read_committed_snapshot on;
-- alter database testdb1 set read_committed_snapshot off;

select is_read_committed_snapshot_on, * from sys.databases where name = N'testdb1'

select * from table1

RaisError(50005, 10, 1)


RAISERROR (N'This is message %s %d %d.', -- Message text.  
           18, -- Severity,  
           1, -- State,  
           N'number', -- First argument.  
           5, 6); -- Second argument.  
-- The message text returned is: This is message number 5.  

THROW 50001, 'An Error Occured',0


DECLARE @ErrorValue int;
RAISERROR(N'%s %d', 16, 1, 
	N'A huge catastrophic fatal error number', 50005) 
	with log, seterror;
SET @ErrorValue = @@ERROR;
IF @ErrorValue <> 0
PRINT 'Error=' + CAST(@ErrorValue AS VARCHAR(8));