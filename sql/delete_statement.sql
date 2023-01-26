delete from table1 where [id] = 1;

--
-- Version 1
--
delete from table0001 where [id] in (select id from the_ids where the_ids.id = 112);
