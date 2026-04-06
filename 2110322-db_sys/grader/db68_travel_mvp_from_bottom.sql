-- Travel MVP Bottom
SELECT
    unique_date.ddate,
    unique_name.pname
FROM
    (
        SELECT DISTINCT
            pname
        FROM
            expense
    ) unique_name
    CROSS JOIN (
        SELECT DISTINCT
            ddate
        FROM
            expense
    ) unique_date
    LEFT JOIN (
        SELECT
            ddate,
            pname,
            SUM(amt) total_spent
        FROM
            expense
        GROUP BY
            ddate,
            pname
    ) spending ON (
        unique_name.pname = spending.pname
        AND unique_date.ddate = spending.ddate
    )
WHERE
    spending.total_spent IS NULL
ORDER BY
    unique_date.ddate,
    unique_name.pname;