SELECT people.name from people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
JOIN ratings ON ratings.movie_id = movies.id
WHERE movies.id IN (
    SELECT movie_id
    FROM stars
    JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
)
AND people.name != 'Kevin Bacon' AND people.birth != 1958;
