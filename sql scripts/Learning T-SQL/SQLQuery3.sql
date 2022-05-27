SELECT [Year], Budget, LEAD(Budget, 1, 0) OVER (ORDER BY [Year]) AS 'Next'
    FROM dbo.Budget
    ORDER BY [Year];