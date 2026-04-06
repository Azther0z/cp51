-- Jurassic World
SELECT
    dino_name,
    dino_type,
    SUM(amount) total_amount
FROM
    dinosaurs
WHERE
    dino_name IN (
        SELECT
            dino_name
        FROM
            dinosaurs
        GROUP BY
            dino_name,
            dino_type
        ORDER BY
            SUM(amount) DESC,
            dino_type,
            dino_name
        LIMIT
            1
    )
GROUP BY
    dino_name,
    dino_type;