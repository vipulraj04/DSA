# Write your MySQL query statement below
select user_id,
count(follower_id ) as followers_count
FROM Followers
GROUP by user_id
ORDER BY user_id ASC