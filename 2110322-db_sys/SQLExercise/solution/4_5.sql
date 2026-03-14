SELECT
    customer_id,
    customer_name,
    COUNT(*) AS number_of_orders
FROM
    customer
    NATURAL JOIN ordert
GROUP BY
    customer_id
ORDER BY
    COUNT(*) desc;