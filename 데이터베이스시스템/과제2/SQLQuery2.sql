-->1.	'Comp. Sci.' 학과에 소속된 어떤 학생보다 많은 학점을 이수한 학생의 이름을 검색. o
select distinct T.ID, T.name
from student as T, student as S
where T.tot_cred>S.tot_cred and S.dept_name='Comp. Sci.'

-->2.	'Comp. Sci. 학과에 소속된 어떤 학생보다 많은 학점을 이수한 학생들 가운데 Comp. Sci.' 학과에 소속되지 않은 학생들의 수를 학과별로 검색. o
select T.dept_name, count(distinct T.ID) as num_st
from student as T, student as S
where T.tot_cred>S.tot_cred and S.dept_name='Comp. Sci.' and T.dept_name!='Comp. Sci.'
group by T.dept_name

-->3.	'Accounting' 학과에 소속된 학생들 중 이름이 'Ch'로 시작하는 학생들에 대한 모든 정보를 검색.  O
select *
from student
where dept_name='Accounting' and name like 'Ch%'

-->4.	예산이 600000 이상 800000 이하인 학과의 학과명과 예산을 예산값 내림차순 기준으로 검색 O
select dept_name, budget
from department
where budget between 600000 and 800000
order by budget desc

-->5.	2006학년도 봄학기에는 강의를 맡았지만 2006학년도 가을학기에는 강의를 맡지 않은 교수들의 교수번호를 검색 O
(select ID from teaches where semester='Spring' and year=2006)
except
(select ID from teaches where semester='Fall' and year=2006)


-->6.	아직 연봉이 정해지지 않은(연봉이 NULL을 가지는) 교수들의 수를 학과별로 검색 o
--> 6번 문제를 풀기위하여 아래 update SQL을 작성, 실행하시오. ('Pol. Sci.' 학과 교수들의 연봉을 null로 변경하는 작업) 
--> update instructor set salary = null where dept_name = 'Pol. Sci.' or dept_name = 'Comp. Sci.' 3/2
update instructor set salary = null where dept_name = 'Pol. Sci.' or dept_name = 'Comp. Sci.'

select dept_name, count(*) cnt
from instructor
where salary is null
group by dept_name

-->7.	학년도, 학기 기준으로 수강신청하여 이수한 학생 수를 검색. (수강신청 후 아직 이수완료하지 않은 경우 grade는 null을 가짐. grade가 'F'인 경우 해당 강좌를 이수하지 않은 것이 됨.) O
select year, semester, count(ID) as num_st
from takes
where grade is not null and grade!='F'
group by year, semester
order by year

select * from takes
-->8.	학과별 지도학생 수를 검색 x
select dept_name, count(*) as 'student number'
from student
group by dept_name

select instructor.dept_name, count(*) num
from advisor, student, instructor
where instructor.ID=advisor.i_ID and advisor.s_ID=student.ID
group by instructor.dept_name

select instructor.dept_name, count(distinct student.name) as num_st
from instructor, student, advisor
where instructor.ID=advisor.i_ID and student.ID=advisor.s_ID
group by instructor.dept_name

-->9.	50명 이상 학생들을 지도하는 교수들의 교수번호와 지도학생 수를 검색. x
select i_ID, count(*) num
from advisor
group by i_ID
having count(*)>=50

select instructor.ID, count(student.name)
from instructor, advisor, student
where advisor.i_ID=instructor.ID and advisor.s_ID=student.ID
group by instructor.ID
having count(student.name)>=50

-->10.	학년도, 강의실(building, room_number) 기준으로 해당 학년도, 강의실에서 진행된 강좌에 참여 한 학생 수를 검색 x
select s.year, building, room_number, count(ID) num_st
from section s, takes t
where s.course_id=t.course_id and s.sec_id=t.sec_id and s.semester=t.semester and s.year=t.year
group by s.year, building, room_number
order by s.year

select s.year, building, room_number, count(s.year) count
from section s, takes t
where s.course_id=t.course_id and s.sec_id=t.sec_id and s.semester=t.semester and s.year=t.year
group by s.year, building, room_number
order by s.year

select s.year, building, room_number, count(distinct ID) count
from section s, takes t
where s.course_id=t.course_id and s.sec_id=t.sec_id and s.semester=t.semester and s.year=t.year
group by s.year, building, room_number
order by s.year

select s.year, building, room_number, count(s.year) count
from section s, takes t
where s.course_id=t.course_id and s.sec_id=t.sec_id and s.semester=t.semester and s.year=t.year
group by s.year, building, room_number

select * from section order by year
select * from takes