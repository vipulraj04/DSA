# Write your MySQL query statement below
select e.name,b.bonus
From Employee as e
LEFT JOIN Bonus as b
ON e.empId=b.empId
HAVING bonus is null OR bonus < 1000