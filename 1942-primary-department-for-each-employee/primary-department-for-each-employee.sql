# Write your MySQL query statement below
select employee_id,department_id
FROM Employee
WHERE primary_flag='Y'
OR employee_id IN(
    select employee_id
    from Employee
    GROUP BY employee_id
    HAVING COUNT(*)=1
)
