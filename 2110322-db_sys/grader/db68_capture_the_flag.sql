-- Capture the Flag
SELECT
    bid,
    title,
    body
FROM
    blog
WHERE
    body ILIKE '%FLAG{________________________________}%'
ORDER BY
    bid;