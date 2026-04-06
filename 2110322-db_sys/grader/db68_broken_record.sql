-- Broken Record
SELECT
    u.studentid AS studentid,
    c.pname AS pname,
    c.cname AS cname
FROM
    userinfo AS u
    JOIN clubreg AS c ON (
        u.studentid = c.studentid
        OR u.pname = c.pname
    )
ORDER BY
    studentid DESC;