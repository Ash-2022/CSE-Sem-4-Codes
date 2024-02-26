-- Q1
select course_id , count(takes.id) as "Students in each Course"
from takes
group by course_id; 

-- Q2
select dept_name , count(student.id) as "No. of Students"
from student
group by dept_name
having count(student.id) > 2;

-- Q3
select dept_name , count(course_id) as "Courses per Department"
from course
group by dept_name;

-- Q4
select dept_name , avg(salary) as "Average Salaries"
from instructor
group by dept_name
having avg(salary) > 42000;

-- Q5
select sec_id , sum(capacity) as "Total Capacity"
from section natural join classroom
where semester = 'Spring' and year = 2009
group by sec_id;

-- Q6
select course_id, prereq.prereq_id
from prereq natural join course 
order by course_id asc;

-- Q7
select *
from instructor
order by salary desc;

-- Q8
with dept_sal(dept_name , totalSalary) as (
    select dept_name , sum(salary) 
    from instructor
    group by dept_name)
select max(dept_sal.totalSalary) as "Max Salary" , dept_name
from dept_sal;

select dept_name , max(T) as "Max Salary"
from (
    select dept_name , sum(salary) as T
    from instructor
    group by dept_name
);

-- Q9
with instr_dept_avg(dept_name , dept_avg_salary) as (
    select dept_name , avg(salary)
    from instructor
    group by dept_name
    having avg(salary) > 42000
)
select avg(dept_avg_salary)
from instr_dept_avg;

-- Q10
with enrollment(sec_id , totalCapacity) as (
    select sec_id , sum(capacity) 
    from section natural join classroom
    where semester = 'Spring' and year = 2010
    group by sec_id
)
select sec_id
from enrollment
where totalCapacity = (
    select max(totalCapacity) 
    from enrollment
);

-- Q11
with cse_instructors(id , name) as (
    select id , name
    from instructor
    where dept_name = 'Comp. Sci.'
)
select name 
from cse_instructors;

-- Q12
with avg_sal_instructors(dept_name , salary , count_id) as (
    select dept_name, avg(salary) , count(instructor.id)
    from instructor
    group by dept_name
)
select * 
from avg_sal_instructors
where count_id > 2;

-- Q13
with max_budget(budget) as (
    select max(budget)
    from department
)
select dept_name
from department
where budget = (
    select budget 
    from max_budget)
group by dept_name;

-- Q14
with avg_sal_all_deptartments(salary) as (
    select avg(salary)
    from instructor
)
select dept_name , avg(salary)
from instructor
group by dept_name
having avg(salary) > (
    select salary 
    from avg_sal_all_deptartments
);
