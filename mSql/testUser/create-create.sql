
SELECT table_name FROM user_tables;

-- 1 create table
create table employee (
  id number,
  name varchar2(6),
  salary number
);

desc employee;

INSERT INTO employee VALUES (101, 'Amit', 30000);
INSERT INTO employee VALUES (201, 'Kapil', 22000);
INSERT INTO employee VALUES (301, 'Rohit', 45000);
INSERT INTO employee VALUES (401, 'Amit', 27000);
INSERT INTO employee VALUES (401, 'Amit', 27000);

select * from EMPLOYEE;

-- * done till here
commit;
