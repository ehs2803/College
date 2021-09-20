create view dept_section_cnt(dept_name, year, cnt) as
select dept_name, year, count(S.course_id)
from course C, section S
where C.course_id=S.course_id
group by dept_name, year
