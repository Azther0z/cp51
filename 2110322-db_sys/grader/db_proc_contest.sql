-- Programming Contest System
SELECT
    author.aname aname,
    task.tname tname
FROM
    (
        SELECT
            tid,
            RANK() OVER (
                ORDER BY
                    COUNT(DISTINCT cid) DESC
            ) solved_rank
        FROM
            submit
        WHERE
            score = 100
        GROUP BY
            tid
    ) solved_table
    JOIN task ON solved_table.tid = task.tid
    JOIN author ON task.aid = author.aid
WHERE
    solved_table.solved_rank = 1
ORDER BY
    author.aid