SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS OFF 
GO



CREATE    PROCEDURE GetEmployeeByName  
@EmployeeID int,
@Count int out
 AS
SELECT @Count=Count(*) FROM Employees
WHERE EMPLOYEEID=@EmployeeID

SELECT * FROM Employees
WHERE EMPLOYEEID=@EmployeeID



GO
SET QUOTED_IDENTIFIER OFF 
GO
SET ANSI_NULLS ON 
GO

