SELECT
    COUNT(*) AS total_orders
FROM
    ordert
WHERE
    '2020-01-10 00:00:00' <= order_date
    AND order_date <= '2020-01-15 23:59:59';