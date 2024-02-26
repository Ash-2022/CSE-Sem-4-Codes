/* Q1 */
create table employee1 (
	EmpNo int primary key,
	EmpName varchar(50) not null,
	Gender varchar(50) not null,
	Salary int not null,
	Address varchar(100) not null,
	DNo int,
	check(Gender in ('M','F'))
);

/* Q2 */
create table Department1 (
	DeptNo int primary key,
	DeptName varchar(50) unique
);

/* Q3 */
alter table Employee1 add(foreign key(DNo) references Department1(DeptNo));

/* Q4 */
insert into Department1 values (1, 'CSE');
insert into Department1 values (2, 'CSE AIML');
insert into Department1 values (3, 'EEE');
insert into Employee1 values (1 , 'Ashvin', 'M' , 1000 , 'Manipal' , 1);
insert into Employee1 values (2 , 'Sambhav', 'M', 1000 , 'Mangalore' , 2);
insert into Employee1 values (3 , 'Shivarth', 'M' , 1000 , 'Pune' , 3);
insert into Employee1 values (4 , 'Nihar', 'M' , 1000 , 'Pune' , 2);

/* Q5 */
insert into employee1 values (4 , 'Shivarth' , 'Male' , 1000 , 'Pune' , 3);
insert into Department1 values (4, 'CSE');

/* Q6 */
delete from Department1 where DeptNo = 2;

/* Q7 */
alter table employee1 modify(
	CONSTRAINT fks foreign key(DNo) references 
	Department1(DeptNo) on delete cascade
);

/* Q8 */
alter table employee1 modify(
	CONSTRAINT xyz Salary default 100000
);

/* Q9 */
select name , dept_name from student;

/* Q10 */
select * from instructor where dept_name = 'Comp. Sci.';

/* Q11 */
select * from course where dept_name = 'Comp. Sci.' and credits = 3;

/* Q12 */
select takes.id , takes.course_id , course.title
from takes , course
where takes.course_id = course.course_id and takes.id = 12345;

/* Q13 */
select * from instructor where Salary between 40000 and 90000;

/* Q14 */
select id from instructor minus (select id from teaches);

/* Q15 */
select name , title , year
from student natural join course natural join section 
where room_number = 514;

/* Q16 */
select name , course.title as c_name 
from student natural join takes natural join course
where year = 2010;

/* Q17 */
select name as inst_salary 
from instructor
where Salary > (
	select min(Salary)
	from instructor
	where dept_name = 'Comp. Sci.'
);

/* Q18 */
select name 
from instructor
where dept_name like '%hy%';

/* Q19 */
select name , length(name)
from student;

/* Q20 */
select dept_name , substr(dept_name , 3 , 3)
from Department;

/* Q21 */
select upper(name) 
from instructor;

/* Q22 */
select nvl(tot_cred , 0)
from student;

/* Q23 */
select Salary , round((Salary/3) , 2)
from instructor;

/* Q24 */
alter table employee1 add(DOB DATE);
update employee1 set dob = to_date(13022004 , 'DDMMYYYY') where EmpNo = 3;
update employee1 set dob = to_date(12022004 , 'DDMMYYYY') where EmpNo = 2;
update employee1 set dob = to_date(14022004 , 'DDMMYYYY') where EmpNo = 4;
update employee1 set dob = to_date(11022004 , 'DDMMYYYY') where EmpNo = 1;
select to_char(DOB , 'DD-MON-YYYY') from employee1;
select to_char(DOB , 'DD-MON-YY') from employee1;
select to_char(DOB , 'DD-MM-YY') from employee1;

/* Q25 */
select to_char(DOB , 'YEAR') from employee1;