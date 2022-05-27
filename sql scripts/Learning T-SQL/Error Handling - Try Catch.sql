
use testdb1
go
begin tran
update table1 set field1 = 999 where [id] = 1

begin try
	update table1 set field1 = 777 where [id] = 2
end try
begin catch
	print N'ERROR_NUMBER() = ' + cast(error_number() as nvarchar(50))
	print N'ERROR_SEVERITY() = ' + cast(error_severity() as nvarchar(50))
	print N'ERROR_MESSAGE() = ' + cast(error_message() as nvarchar(50))
end catch


-- select * from table1

commit tran
-- rollback tran



