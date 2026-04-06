-- Avocado Purchase Order Optimization
SELECT
    id,
    customer,
    order_date,
    delivery_date,
    (delivery_date - order_date) days_late
FROM
    purchase_orders
WHERE
    (delivery_date - order_date) > 5