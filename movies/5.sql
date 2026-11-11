SELECT title,
       YEAR
FROM movies
WHERE title LIKE 'Harry Potter and the%'
ORDER BY YEAR ASC;

-- 5. Titles and years of all Harry Potter movies, in chronological order (title beginning with "Harry Potter and the ...")
