# Write your MySQL query statement below
select a.name,b.unique_id
from Employees as a
LEFT JOIN EmployeeUNI as b
ON a.id=b.id