SELECT
    customer_id,
    customer_name
FROM
    customer
    NATURAL JOIN ordert
GROUP BY
    customer_id
HAVING
    COUNT(*) >= ALL (
        SELECT
            COUNT(*)
        FROM
            ordert
        GROUP BY
            customer_id
    );