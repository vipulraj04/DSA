# Write your MySQL query statement below

SELECT ROUND(SUM(IF(order_date=customer_pref_delivery_date,1,0))*100/
COUNT(DISTINCT (customer_id )),2) AS immediate_percentage 
FROM Delivery
WHERE(customer_id ,order_date) 
IN(select customer_id,min(order_date ) 
from Delivery
GROUP BY customer_id )
