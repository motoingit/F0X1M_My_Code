-- ADDING CONSTRAINTS



                -- AFTER CREATION

-- First, add the Primary Key to the id column
ALTER TABLE UNIVERSITY 
ADD CONSTRAINT pk_univ_id PRIMARY KEY (id);

-- Next, add the Unique rule to the name column
ALTER TABLE UNIVERSITY 
ADD CONSTRAINT uq_univ_name UNIQUE (name);

-- Important Note for NOT NULL Constraints:While most constraints (PRIMARY KEY, UNIQUE, CHECK, FOREIGN KEY) use the ADD keyword, if you ever want to make a column NOT NULL after the table is created, you must use the MODIFY keyword instead:

ALTER TABLE UNIVERSITY 
MODIFY address CONSTRAINT nn_univ_address NOT NULL;



                  -- BEFORE CREATION

-- Table-Level Constrain
CREATE TABLE UNIVERSITY (
  id NUMBER,
  name VARCHAR2(100),
  address VARCHAR2(200),
  CONSTRAINT pk_univ_id PRIMARY KEY (id),
  CONSTRAINT uq_univ_name UNIQUE (name)
);

-- Column-Level Constraint.
CREATE TABLE UNIVERSITY (
  id NUMBER CONSTRAINT pk_univ_id PRIMARY KEY,
  name VARCHAR2(100) CONSTRAINT uq_univ_name UNIQUE,
  address VARCHAR2(200)
);
