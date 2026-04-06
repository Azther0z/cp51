-- Doctor Who
SELECT
    dname Mor_name
FROM
    doctor
WHERE
    d_id NOT IN (
        SELECT
            d_id
        FROM
            work_for
    )
    AND dname LIKE 'C%'
ORDER BY
    dage DESC,
    d_id;