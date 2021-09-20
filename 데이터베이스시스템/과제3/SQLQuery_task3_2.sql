select count(*)
from instructor, advisor
where name='Bertolino' and ID=i_ID



select dept_name, year, count(S.course_id) cnt
from course C, section S
where dept_name='abc' and C.course_id=S.course_id
group by dept_name, year



select title
from teaches T, section S, course C
where ID=36897 and T.course_id=S.course_id 
			and T.sec_id=S.sec_id 
			and T.semester=S.semester 
			and T.year=S.year 
			and S.course_id=C.course_id

