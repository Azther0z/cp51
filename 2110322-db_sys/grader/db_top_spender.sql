-- Top Spender
SELECT
    users.name name,
    SUM(products.price * orders.quantity) total_price
FROM
    orders
    JOIN users ON orders.user_id = users.id
    JOIN products ON orders.product_id = products.id
GROUP BY
    users.name,
    users.id
ORDER BY
    SUM(products.price * orders.quantity) DESC,
    users.id
LIMIT
    1;