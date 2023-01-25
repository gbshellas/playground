select * from table1;
-- This is something else from another developer called dev2
select * from table2;

select the_baby_field, a_new_field from other_table2 
	inner join table3 on (other_table2.id = table3.FK_id);
