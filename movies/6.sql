SELECT AVG(ratings.rating)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2012;-- 6. Average rating of movies in 2012
