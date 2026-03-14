SELECT
    product_id,
    product_description
FROM
    product
WHERE
    product_id IN (
        SELECT
            product_id
        FROM
            order_line
        GROUP BY
            product_id
        HAVING
            COUNT(*) >= ALL (
                SELECT
                    COUNT(*)
                FROM
                    order_line
                GROUP BY
                    product_id
            )
    );