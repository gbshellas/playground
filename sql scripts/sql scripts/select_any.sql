if  4  > Any (select [id] from t1)
	print 'true'
else 
	print 'false'

if  4  > All (select [id] from t1 where [id] between 1 and 3)
	print 'true'
else 
	print 'false'



select avg(grade) from grade group by student_id

select * from Student s 
	where exists 
		(select student_id from grade g 
			where g.student_id = s.[id]  group by student_id having avg(grade) > 8)