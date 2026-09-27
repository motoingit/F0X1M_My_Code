
-- show all table in this user
SELECT table_name FROM user_tables;
SELECT * FROM tab;


-- show {ALL} content of this table
SELECT * FROM UNIVERSITY;

-- show {Filtered-Specifioc} content of this table
SELECT *
FROM UNIVERSITY
WHERE ADDRESS = 'New Delhi';

-- show {Filterd-Codition} content of this table
SELECT *
FROM UNIVERSITY
WHERE id > 1235;
