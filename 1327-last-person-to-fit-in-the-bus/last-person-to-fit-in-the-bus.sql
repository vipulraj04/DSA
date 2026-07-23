# Write your MySQL query statement below
select person_name
from Queue q1
WHERE
(
    select sum(weight)
    from Queue q2
    Where q2.turn <= q1.turn
) <=1000
ORDER BY turn DESC
LIMIT 1;