# Write your MySQL query statement below
select w.id as Id
from Weather as w
JOIN Weather as v
ON DATEDIFF(w.recordDate,v.recordDate)=1
WHERE w.temperature > v.temperature