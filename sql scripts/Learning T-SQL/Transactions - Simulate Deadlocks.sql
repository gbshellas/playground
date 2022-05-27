use testdb1
go
begin tran
update table1 set field1 = 888 where [id] = 2
update table1 set field1 = 666 where [id] = 1

-- insert into table1 values(106, null, null, null)
rollback tran

select * from table1

commit tran

select * from table1