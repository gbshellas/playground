select * from Person.Person a 
where 
	 exists (select * from HumanResources.Employee as b
			where a.BusinessEntityID = b.BusinessEntityID)

order by a.BusinessEntityID


select * from Person.Person a 
where 
	exists (select * from Sales.SalesPerson as b
			where a.BusinessEntityID = b.BusinessEntityID)

order by a.BusinessEntityID