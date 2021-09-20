select title
from teaches T, section S, course C
where ID=22591 and T.course_id=S.course_id 
			and T.sec_id=S.sec_id 
			and T.semester=S.semester 
			and T.year=S.year 
			and S.course_id=C.course_id

select distinct C.title
from teaches T, course C
where T.ID=36897 and T.course_id=C.course_id

select *
from instructor

-->===============================================
select dept_name, year, count(C.course_id)
from course C, section S
where C.course_id=S.course_id
group by dept_name, year
order by dept_name

select dept_name, year, count(S.course_id)
from course C, section S
where C.course_id=S.course_id
group by dept_name, year
order by dept_name

select *
from section

select*
from dept_section_cnt
-->===============================================
select*
from dept_section_cnt
where dept_name='Biology'