# Write your MySQL query statement below
select p.product_id,
ROUND(IFNULL(SUM(p.price * u.units) / SUM(u.units), 0), 2)as average_price
from Prices AS p
LEFT JOIN UnitsSold as u
ON p.product_id = u.product_id AND purchase_date BETWEEN start_date AND end_date 
GROUP BY product_id
