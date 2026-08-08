# Write your MySQL query statement below
select id,count(*)as num from (
select requester_id as id from RequestAccepted 
UNION ALL
select accepter_id from RequestAccepted 
) as t
GROUP by id
ORDER BY num DESC
LIMIT 1