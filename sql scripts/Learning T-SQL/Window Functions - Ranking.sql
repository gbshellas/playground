Use AdventureWorks2019
go 

select p.ProductID
	, p.Name
	, p.ListPrice
	, ROW_NUMBER() over (order by p.listprice asc) as "Row Number"
	, RANK() OVER (ORDER BY p.listprice) AS PriceRank  
    , DENSE_RANK() OVER (ORDER BY p.listprice) AS "Dense Rank"  
    , NTILE(4) OVER (ORDER BY p.listprice) AS Quartile  
from Sales.SalesOrderHeader sh 
	inner join Sales.SalesOrderDetail sd on (sh.SalesOrderID = sd.SalesOrderID)
	inner join Production.Product as p on (sd.ProductID = p.ProductID)
where p.Color is not null
order by "Row Number"

