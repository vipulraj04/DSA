# Write your MySQL query statement below
select
'Low Salary' as category,
COUNT(income) as accounts_count
from Accounts
WHERE income < 20000

UNION ALL

select
'Average Salary' as category,
COUNT(income) as accounts_count
from Accounts
WHERE income >= 20000 AND income <=50000

UNION ALL

select
'High Salary' as category,
COUNT(income) as accounts_count
from Accounts
WHERE income  > 50000