select
a.machine_id,
ROUND(AVG(w.timestamp-a.timestamp),3) as processing_time
from Activity as a
JOIN Activity as w
ON a.machine_id=w.machine_id
AND a.process_id=w.process_id
WHERE a.activity_type ='start'
AND w.activity_type='end'
GROUP BY a.machine_id