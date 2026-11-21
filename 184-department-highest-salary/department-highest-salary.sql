# Write your MySQL query statement below

Select d.name as Department,e.name as Employee,
e.salary as Salary
from Employee as e
JOIN Department as d
ON e.departmentId=d.id
WHERE(e.departmentId,e.salary) IN(
    select departmentId,MAX(salary)
    From Employee
    Group by departmentId
)