-- Travel MVP
SELECT
    ddate,
    pname
FROM
    (
        SELECT
            ddate,
            pname,
            RANK() OVER (
                PARTITION BY
                    ddate
                ORDER BY
                    SUM(amt) DESC
            ) AS spent_rank
        FROM
            expense
        GROUP BY
            ddate,
            pname
    ) tmp
WHERE
    spent_rank = 1
ORDER BY
    ddate,
    pname;