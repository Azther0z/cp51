SELECT DISTINCT
    customer_id,
    customer_name
FROM
    customer
    NATURAL JOIN ordert
WHERE
    '2020-01-10 00:00:00' <= order_date
    AND order_date <= '2020-01-15 23:59:59';