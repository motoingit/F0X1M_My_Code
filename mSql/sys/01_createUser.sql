-- create user
create user moto identified by moto123;

-- delete user
DROP USER zyx_temp CASCADE;

-- configuring user permisstion
GRANT
  CREATE SESSION,
  CREATE TABLE,
  CREATE VIEW,
  CREATE SEQUENCE,
  CREATE PROCEDURE
TO moto;

-- recheck config of user permission
SELECT grantee, privilege
FROM dba_sys_privs
WHERE grantee = 'MOTO';

--! ALTER USER testuser QUOTA UNLIMITED ON USERS;
GRANT UNLIMITED TABLESPACE TO moto;

-- see users
SELECT USERNAME FROM DBA_USERS ORDER BY USERNAME;

--! revoke
REVOKE 
  CREATE SESSION,
  CREATE TABLE,
  CREATE VIEW,
  CREATE SEQUENCE,
  CREATE PROCEDURE
FROM zyx_temp;

