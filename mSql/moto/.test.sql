
-- table desc
desc UNIVERSITY;

-- to check constrains on table
SELECT constraint_name, constraint_type, status
  from user_constraints where table_name = 'TABLE_NAME';
