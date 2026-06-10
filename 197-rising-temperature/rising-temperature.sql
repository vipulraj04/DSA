select w.id
FROM Weather as w
JOIN Weather as v
where DATEDIFF(w.recordDate,v.recordDate)=1
AND w.temperature > v.temperature 