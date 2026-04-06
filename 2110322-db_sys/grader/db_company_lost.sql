-- The Company Lost
SELECT
    EXTRACT(
        YEAR
        FROM
            orders.order_date
    ) order_year,
    ROUND(
        SUM(
            products.unit_price * order_details.quantity * order_details.discount
        )::numeric,
        2
    ) discount_amount
FROM
    order_details
    JOIN products ON order_details.pid = products.pid
    JOIN orders ON orders.oid = order_details.oid
GROUP BY
    order_year
ORDER BY
    order_year DESC