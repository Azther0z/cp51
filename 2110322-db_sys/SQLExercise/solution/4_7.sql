SELECT
    product_id,
    product_description
FROM
    product
    NATURAL JOIN order_line
GROUP BY
    product_id
HAVING
    SUM(ordered_quantity) >= ALL (
        SELECT
            SUM(ordered_quantity)
        FROM
            order_line
        GROUP BY
            product_id
    );