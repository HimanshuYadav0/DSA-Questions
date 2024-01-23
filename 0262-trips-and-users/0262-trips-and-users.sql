# Write your MySQL query statement below
SELECT request_at AS Day,
       ROUND(SUM(CASE WHEN status = 'cancelled_by_driver' OR status = 'cancelled_by_client' THEN 1 ELSE 0 END) 
             / COUNT(DISTINCT id), 2) AS 'Cancellation Rate'
FROM Trips
JOIN Users AS c ON client_id = c.users_id AND c.banned = 'No'
JOIN Users AS d ON driver_id = d.users_id AND d.banned = 'No'
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;
