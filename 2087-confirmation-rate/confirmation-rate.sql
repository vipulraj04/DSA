# Write your MySQL query statement below
Select s.user_id,IFNULL(round(sum(action='confirmed')/count(*),2),0) as confirmation_rate
from Signups as s
LEFT JOIN Confirmations as c
ON s.user_id=c.user_id
GROUP BY s.user_id