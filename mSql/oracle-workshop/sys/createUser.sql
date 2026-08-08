-- create user
create user testuser identified by testuser123;

-- configuring user permisstion
GRANT
  CREATE SESSION,
  CREATE TABLE,
  CREATE VIEW,
  CREATE SEQUENCE,
  CREATE PROCEDURE
TO testuser;

--! ALTER USER testuser QUOTA UNLIMITED ON USERS;
GRANT UNLIMITED TABLESPACE TO testuser;

--see users
SELECT USERNAME FROM DBA_USERS ORDER BY USERNAME;
