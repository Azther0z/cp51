-- Most-Viewed
SELECT
    movie.mid,
    movie.title,
    rank_table.total_views
FROM
    (
        SELECT
            mid,
            COUNT(*) total_views,
            RANK() OVER (
                ORDER BY
                    COUNT(*) DESC
            ) view_rank
        FROM
            customer
        GROUP BY
            mid
    ) rank_table
    JOIN movie ON movie.mid = rank_table.mid
WHERE
    rank_table.view_rank = 1
ORDER BY
    movie.title;