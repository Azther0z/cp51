SELECT
    customer_id,
    customer_name,
    COUNT(*) AS order_count
FROM
    customer
    NATURAL JOIN ordert
GROUP BY
    customer_id
ORDER BY
    COUNT(*) desc
LIMIT
    3;