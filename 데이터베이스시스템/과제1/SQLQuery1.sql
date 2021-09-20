select name, tot_cred
from student
where dept_name='Physics'

select title, credits
from course
where dept_name='Physics' and credits >= 3

select name, salary
from department, instructor
where budget>=100000 and department.dept_name=instructor.dept_name

select distinct name, dept_name
from teaches, instructor
where year= 2009 and semester = 'Fall' and instructor.ID=teaches.ID

select student.name
from student, advisor, instructor
where instructor.dept_name='Physics' and instructor.ID=advisor.i_ID and advisor.s_ID=student.ID