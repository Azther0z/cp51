-- Coop Store
SELECT DISTINCT
    customer.cname
FROM
    placement
    JOIN product ON placement.pid = product.pid
    JOIN customer ON placement.cid = customer.cid
WHERE
    product.pprice > (
        SELECT
            AVG(pprice)
        FROM
            product
        GROUP BY
            pcategory
        ORDER BY
            COUNT(pid) DESC
        LIMIT
            1
    )
ORDER BY
    customer.cname;