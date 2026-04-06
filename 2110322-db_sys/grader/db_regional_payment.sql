-- Regional Payment
SELECT
    customer.postal_code,
    SUM(order_line.o_quantity * product.standard_price) total_payment
FROM
    customer
    JOIN ordert ON ordert.c_id = customer.c_id
    JOIN order_line ON ordert.o_id = order_line.o_id
    JOIN product ON order_line.p_id = product.p_id
GROUP BY
    customer.postal_code
ORDER BY
    customer.postal_code;