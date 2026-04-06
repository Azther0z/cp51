-- Reseller
WITH
    sales_sum AS (
        SELECT
            pid,
            SUM(quantity_sold) total_sales
        FROM
            PRODUCT_SALES
        WHERE
            sale_date >= '2022-01-01'
            AND sale_date <= '2025-01-01'
        GROUP BY
            pid
        HAVING
            SUM(quantity_sold) <= 100
    )
SELECT
    PRODUCT.pname pname,
    PRODUCT.pprice pprice,
    sales_sum.total_sales total_sales
FROM
    PRODUCT
    JOIN sales_sum ON PRODUCT.pid = sales_sum.pid
ORDER BY
    sales_sum.total_sales DESC,
    PRODUCT.pprice,
    PRODUCT.pname
LIMIT
    3;