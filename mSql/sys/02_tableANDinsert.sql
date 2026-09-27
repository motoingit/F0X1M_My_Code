create table UNIVERSITY(
  id number,
  name varchar(100),
  address varchar(200)
);

insert 
  into UNIVERSITY(id, name, address)
  values(1234, 'Graphic Era Hill University', 'Dehradun');

INSERT INTO UNIVERSITY 
  VALUES (1234, 'Graphic Era Hill University', 'Dehradun');

INSERT ALL
  INTO UNIVERSITY (id, name, address) VALUES (1235, 'Doon University', 'Dehradun')
  INTO UNIVERSITY (id, name, address) VALUES (1236, 'Another University', 'New Delhi')
SELECT * FROM dual;

-- -- 3. Inserting Data from Another Table
-- INSERT INTO UNIVERSITY (id, name, address)
-- SELECT temp_id, temp_name, temp_city FROM TEMP_UNIVERSITIES;
