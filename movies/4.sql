SELECT COUNT(movies.title)
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating = 10.0;-- 4. Number of movies with a 10.0 rating
