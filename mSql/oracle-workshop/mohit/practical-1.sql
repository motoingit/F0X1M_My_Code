-- EMPLOYEE TABLE (Parent Table)
create table employee (
   employee_id   number generated always as identity ( start with 100 increment by 1 ) primary key,
   name          varchar2(50) not null,
   phone         varchar2(15),
   salary        number(10,2),
   experience    number(2),
   join_date     date,
   employee_type varchar2(20)
);

-- DOCTOR TABLE
create table doctor (
   employee_id    number primary key,
   specialization varchar2(50),
   qualification  varchar2(100),
   foreign key ( employee_id )
      references employee ( employee_id )
);

---------------------------------------------------------
-- NURSE TABLE
---------------------------------------------------------

create table nurse (
   employee_id number primary key,
   ward_no     number(3),
   foreign key ( employee_id )
      references employee ( employee_id )
);

---------------------------------------------------------
-- MANAGEMENT TABLE
---------------------------------------------------------

create table management (
   employee_id number primary key,
   department  varchar2(50),
   designation varchar2(50),
   foreign key ( employee_id )
      references employee ( employee_id )
);

---------------------------------------------------------
-- DRIVER TABLE
---------------------------------------------------------

create table driver (
   employee_id  number primary key,
   license_no   varchar2(30),
   vehicle_type varchar2(30),
   foreign key ( employee_id )
      references employee ( employee_id )
);

---------------------------------------------------------
-- VENDOR TABLE
---------------------------------------------------------

create table vendor (
   employee_id     number primary key,
   company_name    varchar2(100),
   supply_type     varchar2(50),
   contract_period number(3),
   foreign key ( employee_id )
      references employee ( employee_id )
);

-- PATIENT TABLE
create table patient (
   patient_id     number generated always as identity ( start with 100000 increment by 1 ) primary key,
   name           varchar2(50) not null,
   gender         varchar2(10),
   age            number(3),
   blood_group    varchar2(5),
   phone          varchar2(15),
   address        varchar2(100),
   admission_date date,
   disease        varchar2(100)
);

--insert doctor
insert into employee (
   name,
   phone,
   salary,
   experience,
   join_date,
   employee_type
) values
   ( 'Mohit Singh',
     '9105770414',
     5000.79,
     7,
     sysdate,
     'DOCTOR' );

insert into doctor (
   specialization,
   qualification
) values
   (
     'Bone',
     'MBBS' );

--
SELECT * FROM employee;
SELECT * FROM doctor;
