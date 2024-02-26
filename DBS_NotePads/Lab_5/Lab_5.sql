--Q1-
select Bdate , address 
from employee
where Fname = 'John' and minit = 'B' and Lname = 'Smith';

select Fname || ' ' || minit || ' ' || Lname as name , address
from employee natural join department
where Dname = 'Research';

--Q2-
select Pnumber , Dname , Lname , Address , Bdate , Mgr_ssn 
from project natural join department natural join employee
where Plocation = 'Stafford' and mgr_ssn = super_ssn; 

--Q3-
select e1.Fname, e1.Lname, e2.Fname, e2.Lname 
from employee e1, employee e2 
where e1.super_ssn = e2.ssn;

--Q4-
select Pnumber
from project natural join department natural join employee
where Lname = 'Smith';

--Q5-
select FNAME, lname, (salary*1.1) as res_salary 
from employee e,department d, project p 
where e.dno = d.dnumber and p.pname = 'ProductX' and p.dnum = d.dnumber;

--Q6-
select dname, lname,fname, pname 
from employee e, project p, department d 
where e.dno = p.dnum and p.dnum = d.dnumber 
order by dname, lname, fname;

--Q7-
select Fname || ' ' || minit || ' ' || Lname as name 
from employee, dependent 
where fname = dependent_name and employee.sex = dependent.sex;

--Q8-
select distinct Fname || ' ' || minit || ' ' || Lname as name
from employee, dependent 
where employee.ssn not in (
	select essn 
	from dependent
);

--Q9-
select Fname || ' ' || minit || ' ' || Lname as name 
from employee e, department d 
where d.mgr_ssn = e.ssn and e.ssn in (
	select essn from dependent
);


--Q10-
select sum(salary), max(salary), min(salary), avg(Salary) 
from employee;

--Q11-
select pnumber,pname, count(ssn) 
from project p, employee e 
where p.dnum = e.dno 
group by pnumber,pname;

--Q12-
select p.pnumber,p.pname,count(w.essn) 
from (project p join works_on w on p.pnumber=w.pno ) 
group by p.pnumber,p.pname 
having count(w.essn)> 2 
order by p.pnumber;

--Q13-

with e_sal(dno1,val) as(
	select dno,count(salary) 
	from employee 
	where salary>40000 
	group by dno 
)
select dno,e_sal.val 
from (employee join e_sal on employee.dno=e_sal.dno1 ) 
group by dno,val 
having count(ssn)>2;