# Write your MySQL query statement below
select ROUND(SUM(tiv_2016),2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 in(
    select tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) >1
) AND (lat,lon) IN(
    select lat,lon 
    from Insurance 
    GROUP BY lat,lon
    HAVING COUNT(*) =1
)