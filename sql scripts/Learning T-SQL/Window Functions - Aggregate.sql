Use AdventureWorks2019
go 

select sh.SalesOrderID
	, p.Name
	, p.ProductNumber
	, p.Color
	, p.Weight
	, sum(p.Weight)
		Over(Partition by p.Color, p.productnumber) as WeightByColor


from Sales.SalesOrderHeader sh 
	inner join Sales.SalesOrderDetail sd on (sh.SalesOrderID = sd.SalesOrderID)
	inner join Production.Product as p on (sd.ProductID = p.ProductID)
where p.Color is not null
order by p.ProductNumber


/* Similar single Data with Group By */
/*
select p.ProductNumber,
	p.Color,
	sum(p.Weight)
from Sales.SalesOrderHeader sh 
	inner join Sales.SalesOrderDetail sd on (sh.SalesOrderID = sd.SalesOrderID)
	inner join Production.Product as p on (sd.ProductID = p.ProductID)
where p.Color is not null
group by p.Color, p.ProductNumber
order by p.ProductNumber
*/