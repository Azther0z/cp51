SELECT
    d.DName department
FROM
    (
        SELECT
            DID,
            COUNT(EID) son_count
        FROM
            Employees
        WHERE
            EName ILIKE '%son%'
        GROUP BY
            DID
    ) e_count
    JOIN Departments d ON e_count.DID = d.DID
ORDER BY
    e_count.son_count DESC,
    d.DName
LIMIT
    1;