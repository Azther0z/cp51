DELETE FROM order_line
WHERE
    order_id = 3;

DELETE FROM order_line
WHERE
    order_id = 4;

DELETE FROM order_line
WHERE
    order_id = 5;

DELETE FROM ordert
WHERE
    customer_id = 10001;

DELETE FROM customer
WHERE
    customer_id = 10001;

SELECT
    *
FROM
    customer
    NATURAL JOIN ordert
    NATURAL JOIN order_line;