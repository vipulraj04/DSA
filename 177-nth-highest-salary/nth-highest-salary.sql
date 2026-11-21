CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (

    select max(salary) from
    (select salary,DENSE_RANK() 
    OVER(ORDER BY salary Desc) as rnk
    from Employee) as temp
    Where rnk=N

  );
END