-- Push Ups
SELECT
    users.name
FROM
    users
    JOIN (
        SELECT
            ssn,
            SUM(push_count) total_count
        FROM
            workout
        GROUP BY
            ssn
    ) workout_sum ON users.ssn = workout_sum.ssn
WHERE
    (
        workout_sum.total_count >= 40
        AND users.age >= 22
        AND users.age <= 60
        AND users.sex = 'F'
    )
ORDER BY
    workout_sum.total_count DESC,
    users.ssn
LIMIT
    5;