# Write your MySQL query statement below
select
max(distinct num) as num
from (
    select num from MyNumbers
    GROUP BY num
    having count(*)=1
)as t;