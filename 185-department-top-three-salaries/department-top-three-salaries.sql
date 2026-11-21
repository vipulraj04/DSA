# Write your MySQL query statement below
select Department,Employee,Salary From(

    select d.name as Department,
    e.name as Employee,
    e.salary as Salary,
    DENSE_RANK() OVER (partition by e.departmentId ORDER BY
    e.salary DESC)as rnk
    From Employee as e
    JOIN Department as d
    ON e.departmentId=d.id
)AS TEMP
WHERE rnk<=3