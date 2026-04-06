-- Dessert Top Spender
SELECT
    customers.name name,
    SUM(orders.amount * desserts.price) total
FROM
    orders
    JOIN desserts ON orders.d_id = desserts.id
    JOIN customers ON orders.c_id = customers.id
GROUP BY
    customers.id,
    customers.name
ORDER BY
    total DESC,
    customers.id
LIMIT
    1;