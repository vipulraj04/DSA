# Write your MySQL query statement below
SELECT visited_on,
(
    select sum(amount)
    from Customer
    WHERE visited_on BETWEEN DATE_SUB(c.visited_on,interval 6 day)
    AND c.visited_on
) as amount,
ROUND((
    select sum(amount)/7
    from Customer
    WHERE visited_on BETWEEN DATE_SUB(c.visited_on,interval 6 day)
    AND c.visited_on
),2) AS average_amount
from Customer c
WHERE visited_on>=(
    select DATE_ADD(min(visited_on),INTERVAL 6 DAY)
    FROM Customer
)
GROUP by visited_on
ORDER by visited_on