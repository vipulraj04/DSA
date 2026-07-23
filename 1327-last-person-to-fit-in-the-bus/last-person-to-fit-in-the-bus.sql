# Write your MySQL query statement below
select
q1.person_name
FROM Queue q1
JOIN Queue q2
ON q2.turn <=q1.turn
GROUP BY q1.turn,q1.person_name
HAVING SUM(q2.weight)<=1000
ORDER by q1.turn DESC
LIMIT 1