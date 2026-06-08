# Write your MySQL query statement below
SELECT
CASE
WHEN ID= (SELECT MAX(id) FROM Seat) AND MOD(ID,2)=1
THEN ID
WHEN MOD(ID,2)=1
THEN ID+1
ELSE
ID-1
END 
AS id,student
FROM Seat
ORDER BY id