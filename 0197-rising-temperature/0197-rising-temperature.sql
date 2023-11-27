# Write your MySQL query statement below
SELECT id
FROM Weather
WHERE temperature > (SELECT temperature FROM Weather W2 WHERE W2.recordDate = DATE_SUB(Weather.recordDate, INTERVAL 1 DAY))
