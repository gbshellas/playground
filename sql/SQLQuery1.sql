select * from PosModelProjectPlugIns

if 1=2 return

Print N'Start Main Program'
if 1=1 goto jmp1
Print N'Hello world must not been seen'
select N'Count(*) PosModelProjectPlugins', count(*) from PosModelProjectPlugIns
jmp1:
Print N'jmp1'
select N'Count(*) PosModel', count(*) from PosModel


