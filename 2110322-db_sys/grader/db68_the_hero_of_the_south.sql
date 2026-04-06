-- Hero of the South
WITH
    southern_party AS (
        SELECT DISTINCT
            party_id
        FROM
            hero
        WHERE
            region = 'south'
    ),
    healer_count AS (
        SELECT
            COUNT(*) AS healer_count,
            party_id
        FROM
            hero
        WHERE
            hero.role = 'healer'
        GROUP BY
            party_id
    ),
    fighter_count AS (
        SELECT
            COUNT(*) AS fighter_count,
            party_id
        FROM
            hero
        WHERE
            hero.role = 'fighter'
        GROUP BY
            party_id
    ),
    magician_count AS (
        SELECT
            COUNT(*) AS magician_count,
            party_id
        FROM
            hero
        WHERE
            hero.role = 'magician'
        GROUP BY
            party_id
    ),
    hero_count AS (
        SELECT
            COUNT(*) AS hero_count,
            party_id
        FROM
            hero
        GROUP BY
            party_id
    ),
    southern_party_extend AS (
        SELECT
            *
        FROM
            southern_party
            JOIN party ON southern_party.party_id = party.party_id
            JOIN healer_count ON healer_count.party_id = southern_party.party_id
            JOIN fighter_count ON fighter_count.party_id = southern_party.party_id
            JOIN magician_count ON magician_count.party_id = southern_party.party_id
            JOIN hero_count ON hero_count.party_id = southern_party.party_id
    ),
    kill_count AS (
        SELECT
            COUNT(DISTINCT battle_id) AS monsters_killed,
            party_id
        FROM
            southern_party_extend
            JOIN battle ON southern_party_extend.party_id = battle.party_id
            JOIN monster ON battle.monster_id = southern_party_extend.monster_id
        WHERE
            (
                southern_party_extend.healer_count >= monster.req_healer
                AND southern_party_extend.magician_count >= monster.req_magician
                AND southern_party_extend.fighter_count >= monster.req_fighter
                AND southern_party_extend.hero_count >= monster.req_hero
            )
        GROUP BY
            party_id
    ),
    damage_sum AS (
        SELECT
            SUM(damage) AS total_damage,
            party_id
        FROM
            battle
            JOIN monster ON battle.monster_id = monster.monster_id
        GROUP BY
            battle.party_id
    )
SELECT
    party_name,
    monsters_killed
FROM
    southern_party_extend
    JOIN damage_sum ON southern_party_extend.party_id = damage_sum.party_id
    JOIN kill_count ON southern_party_extend.party_id = kill_count.party_id
WHERE
    (max_hp - total_damage >= 0.7 * max_hp)
ORDER BY
    monsters_killed DESC,
    party_name