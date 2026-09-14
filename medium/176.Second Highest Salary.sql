# Write your MySQL query statement below
select (SELECT DISTINCT salary FROM Employee
ORDER BY salary desc
limit 1 offset 1)
as SecondHighestSalary;