
-- show only current user
SHOW USER;

-- show all users in sys
SELECT USERNAME FROM DBA_USERS ORDER BY USERNAME;

-- config command
SELECT name, value, description FROM v$parameter WHERE isdefault = 'FALSE';
