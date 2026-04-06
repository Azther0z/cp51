-- Lonely Poet
SELECT DISTINCT
    poets.name,
    poets.era,
    poets.birth_year
FROM
    poets
    JOIN poems ON poets.poet_id = poems.poet_id
WHERE
    poems.written_year >= 1800
    AND poems.written_year <= 1900
    AND poems.lines >= 4
    AND (
        poems.mood ILIKE 'sad%'
        OR poems.mood ILIKE 'love%'
    )
    AND poems.title ILIKE '%lonely%'
ORDER BY
    poets.name,
    poets.era,
    poets.birth_year;