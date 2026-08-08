create table student(
  student_id number primary key,
  student_name varchar(10),
  course_id number,
  location varchar(10),
  age number,
  email varchar(10)
);

create table course(
  course_id number,
  student_id number,
  course_name varchar(10),
  credit number,

  CONSTRAINT FK_std_id FOREIGN KEY (student_id) 
    REFERENCES student(student_id)
);

SELECT table_name FROM user_tables;

insert into student values(100, 'Mohit', 6, 'dehradun', 21, 'mohitsingh@gmail.com');
insert into course values(6, 100,"Btehc",3);
