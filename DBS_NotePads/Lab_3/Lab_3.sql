-- Q1
(select title
from section natural join course 
where semester = 'Fall' and year = 2009) union(
	select title
	from section natural join course where semester = 'Spring' and year = 2010)
-- Q2
(select title
from section natural join course 
where semester = 'Fall' and year = 2009) intersect(
	select title
	from section natural join course where semester = 'Spring' and year = 2010
);
-- Q3
(select title
from section natural join course 
where semester = 'Fall' and year = 2009) minus(
	select title
	from section natural join course where semester = 'Spring' and year = 2010
);
-- Q4
(select title 
from course) minus 
(select c.title 
from course c, takes t 
where t.course_id = c.course_id
);
-- Q5
select course_id, title 
from course 
where course_id in (
    select course_id 
    from section 
    where semester = 'Fall' and year = 2009) and course_id in (
        select course_id 
        from section 
        where semester = 'Spring' and year = 2010
);
-- Q6
select count(id) 
from takes 
where course_id in (
    select course_id 
    from teaches 
    where id = 10101
);
-- Q7
select course_id, title 
from course 
where course_id in (
    select course_id 
    from section 
    where semester = 'Fall' and year = 2009) and course_id not in (
        select course_id 
        from section 
        where semester = 'Spring' and year = 2010
);
-- Q8
select name 
from student 
where name in (
    select name 
    from instructor
);
-- Q9
select name 
from instructor 
where salary > some(
    select salary 
    from instructor 
    where dept_name = 'Biology'
);
-- Q10
select name 
from instructor 
where salary > all(
    select salary 
    from instructor 
    where dept_name = 'Biology'
);
-- Q11
select * 
from (
    select dept_name, avg(salary) 
    from instructor 
    group by dept_name 
    order by avg(salary) desc) 
where rownum = 1;
-- Q12
select dept_name 
from department 
where budget < all(
    select avg(salary) 
    from instructor
);
-- Q13
select course_id, title 
from course 
where exists(
    select course_id 
    from section 
    where semester = 'Fall' and year = 2009 and course.course_id = section.course_id
)
intersect
select course_id, title 
from course 
where exists(
    select course_id 
    from section 
    where semester = 'Spring' and year = 2010 and course.course_id = section.course_id
);
-- Q14
select name, id 
from student 
where exists (
    select t.id 
    from takes t, course c 
    where t.course_id = c.course_id and c.dept_name = 'Biology' and student.id = t.id
);
-- Q15
select title 
from course 
where course_id in (
    select course_id 
    from section 
    where year = 2009 
    group by course_id 
    having count(course_id) <= 1
);
-- Q16
select student.name 
from student 
where id in (
	select id 
    from takes 
    where course_id in (
        select course_id 
        from takes 
        where course_id in (
            select course_id 
            from course 
            where dept_name = 'Comp. Sci.')) 
    group by id
    having count(takes.course_id) >= 2
);
-- Q17
select dept_name, avg(salary) 
from instructor 
group by dept_name 
having avg(salary) > 42000;
-- Q18
create view all_courses as
select title, building , room_number 
from section natural join course
where course_id in (
    select course_id 
    from course 
    where dept_name = 'Physics' and course_id in (
        select course_id 
        from teaches 
        where semester = 'Fall' and year = 2009
    )
);
-- Q19
select title 
from all_courses;
-- Q20
create view department_total_salary as 
select instructor.dept_name , sum(salary) as total_salary 
from instructor 
group by dept_name , xyz;


select * from instructor;
select * from department;
select * from instructor natural join department;