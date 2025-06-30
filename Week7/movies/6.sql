SELECT avg(ratings.rating) from ratings
join movies on ratings.movie_id = movies.id
where year = 2012;
