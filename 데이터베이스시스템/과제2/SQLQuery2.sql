-->1.	'Comp. Sci.' �а��� �Ҽӵ� � �л����� ���� ������ �̼��� �л��� �̸��� �˻�. o
select distinct T.ID, T.name
from student as T, student as S
where T.tot_cred>S.tot_cred and S.dept_name='Comp. Sci.'

-->2.	'Comp. Sci. �а��� �Ҽӵ� � �л����� ���� ������ �̼��� �л��� ��� Comp. Sci.' �а��� �Ҽӵ��� ���� �л����� ���� �а����� �˻�. o
select T.dept_name, count(distinct T.ID) as num_st
from student as T, student as S
where T.tot_cred>S.tot_cred and S.dept_name='Comp. Sci.' and T.dept_name!='Comp. Sci.'
group by T.dept_name

-->3.	'Accounting' �а��� �Ҽӵ� �л��� �� �̸��� 'Ch'�� �����ϴ� �л��鿡 ���� ��� ������ �˻�.  O
select *
from student
where dept_name='Accounting' and name like 'Ch%'

-->4.	������ 600000 �̻� 800000 ������ �а��� �а���� ������ ���갪 �������� �������� �˻� O
select dept_name, budget
from department
where budget between 600000 and 800000
order by budget desc

-->5.	2006�г⵵ ���б⿡�� ���Ǹ� �þ����� 2006�г⵵ �����б⿡�� ���Ǹ� ���� ���� �������� ������ȣ�� �˻� O
(select ID from teaches where semester='Spring' and year=2006)
except
(select ID from teaches where semester='Fall' and year=2006)


-->6.	���� ������ �������� ����(������ NULL�� ������) �������� ���� �а����� �˻� o
--> 6�� ������ Ǯ�����Ͽ� �Ʒ� update SQL�� �ۼ�, �����Ͻÿ�. ('Pol. Sci.' �а� �������� ������ null�� �����ϴ� �۾�) 
--> update instructor set salary = null where dept_name = 'Pol. Sci.' or dept_name = 'Comp. Sci.' 3/2
update instructor set salary = null where dept_name = 'Pol. Sci.' or dept_name = 'Comp. Sci.'

select dept_name, count(*) cnt
from instructor
where salary is null
group by dept_name

-->7.	�г⵵, �б� �������� ������û�Ͽ� �̼��� �л� ���� �˻�. (������û �� ���� �̼��Ϸ����� ���� ��� grade�� null�� ����. grade�� 'F'�� ��� �ش� ���¸� �̼����� ���� ���� ��.) O
select year, semester, count(ID) as num_st
from takes
where grade is not null and grade!='F'
group by year, semester
order by year

select * from takes
-->8.	�а��� �����л� ���� �˻� x
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

-->9.	50�� �̻� �л����� �����ϴ� �������� ������ȣ�� �����л� ���� �˻�. x
select i_ID, count(*) num
from advisor
group by i_ID
having count(*)>=50

select instructor.ID, count(student.name)
from instructor, advisor, student
where advisor.i_ID=instructor.ID and advisor.s_ID=student.ID
group by instructor.ID
having count(student.name)>=50

-->10.	�г⵵, ���ǽ�(building, room_number) �������� �ش� �г⵵, ���ǽǿ��� ����� ���¿� ���� �� �л� ���� �˻� x
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