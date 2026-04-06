-- Max Record
SELECT
    student.name
FROM
    student
WHERE
    score >= ALL (
        SELECT
            score
        FROM
            student
    )
ORDER BY
    student.id
LIMIT
    1;