# Write your MySQL query statement below
select Department,Employee,Salary from(
    select d.name as Department,
    e.name as Employee,e.salary as salary,
    DENSE_RANK() OVER(partition by e.departmentId 
    ORDER BY e.salary DESC) AS rnk
    From Employee as e
    JOIN Department as d
    ON e.departmentId=d.id
) as temp
where rnk=1