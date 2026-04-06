-- Max Purchase
SELECT
    customer.first_name first_name
FROM
    customer
    JOIN invoice ON customer.cus_id = invoice.cus_id
GROUP BY
    customer.cus_id
ORDER BY
    SUM(invoice.total_spent) DESC,
    COUNT(invoice.id),
    customer.cus_id
LIMIT
    1;