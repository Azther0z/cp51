SELECT
    SUM(ordered_quantity * standard_price) AS total_payment
FROM
    order_line
    NATURAL JOIN product
WHERE
    order_id = 3;