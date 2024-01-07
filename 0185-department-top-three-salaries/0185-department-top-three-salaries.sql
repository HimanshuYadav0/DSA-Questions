# Write your MySQL query statement below
WITH RankedSalaries AS (
    SELECT
        e.id AS employee_id,
        e.name AS employee,
        e.salary,
        e.departmentId,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS salary_rank
    FROM Employee e
)
SELECT
    d.name AS Department,
    r.employee AS Employee,
    r.salary AS Salary
FROM RankedSalaries r
JOIN Department d ON r.departmentId = d.id
WHERE r.salary_rank <= 3;
