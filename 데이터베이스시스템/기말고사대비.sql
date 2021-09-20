/*
건물명이 ‘Watson’인 건물에서 운영중인 학과에 소속된 교수들의 평균연봉을 학과별로 구
분하여 조회하는 SQL을 작성하시오. 단, where 절에 IN을 이용하는 중첩하위 질의(Nested 
SQL)를 사용하시오. from 절에 Cartesian Product(카티션 곱)를 사용하지 마시오
*/
select dept_name, avg(salary) as avg_salary
from instructor
where dept_name in (select dept_name
                 from department
                  where building='Main')
group by dept_name

select *
from department

select dept_name, avg(salary)
from instructor
group by dept_name

/*
takes 테이블의 grade 컬럼은 학생이 강좌를 이수 완료한 경우 성적으로 ‘A’, ‘B’, ‘C’, ‘D’, ‘F’를
가진다. 하지만, 수강 중에는 아직 이수 완료하지 않은 상태이므로 grade 컬럼은 null을 가
진다. 학과 ‘Computer Engineering’에 소속된 학생들 가운데 현재 1개 이상 강좌들을 수강
중에 있는 학생들의 ID, name을 조회한 결과를 제공하는 SQL을 작성하시오. 조회 결과는
중복되지 않은 내용으로 구성되도록 하시오. 단, where 절에 EXISTS을 이용하는 중첩하위
질의(Nested SQL)를 사용하시오. from 절에 Cartesian Product(카티션 곱)를 사용하지 마시오
*/
select distinct ID, name
from student s
where dept_name='Biology'
	and exists(select *
			   from takes T
			   where S.ID=T.ID and grade is null )

			  

select distinct ID, name
from student s
where exists(select *
			   from takes T
			   where S.ID=T.ID and grade is null )

select *
from takes

select *
from takes
where grade is null

select *
from student
where ID=98988


/*
지금까지 한 번도 강좌를 맡아 강의에 참여하지 않은 교수의 이름과 학과명을 조회하는
SQL을 left outer join을 이용하여 작성하시오
*/
select I.name, I.dept_name
from instructor I left outer join teaches T on T.ID = I.ID
where course_id is null

/*
advisor 테이블을 주키(Primary key)는 아래 스키마 다이아그램과 같이 (s_id)이다. 지도를 맡
은 학생들이 20명 이상인 교수인 경우 연봉(salary)를 현재 연봉에서 5% 인상한 값으로 변
경하는 SQL을 작성하시오.
*/
update instructor
set salary = salary*1.05
from advisor 
where 20<=(select count(*)
		   from advisor
		   where i_ID=ID)

select count(*)
from advisor
where i_ID=6569

select *
from instructor
where id=6569
-->105311.38

begin tran
update instructor
set salary=100000
where ID=6569

rollback tran

select *
from advisor

select i_ID
from advisor

-->20명이상 지도하는 교수들의 연봉을 조회하시오
select ID
from instructor
where 20<=(select count(*)
		   from advisor 
		   where i_ID=ID)

/*
사용자 ‘김갑동’에게 department 테이블에 대한 select 권한을 부여하는 SQL을 작성하시오.
*/
grant select on department to '김갑동'

/*
4. 데이터 중복(Data Redundancy)에 따른 장점 1가지와 단점 2가지를 제시하시오.


5. 개체무결성제약조건(Entity Integrity Constraint)을 정의하고 SQL의 Create table 에서 이를 구
현하는 방안을 제시하시오.


6. 트랜잭션(Transaction)의 원자성(Atomicity)를 설명하시오.
트랜잭션의 원자성(atomicity)은 트랜잭션을 구성하는 연산들이 모두 정상적으로 실행되거나 하나도 실행되지 않아야 한다는 all-or-nothing 방식을 의미한다.

7. 주어진 스키마 다이어그램에서 course 테이블과 department 테이블은 ‘교과목 운영’이라는
의미로 연결되어 있다. 이를 표현하기 위한 course 와 department 에 대한 create table 문
이 아래와 같다. 학과가 없어질 경우 해당 학과가 운영하고 있던 교과목들도 함께 삭제되
도록 create table course 문 전체를 다시 작성하시오.
create table course (
 course_id varchar(8) primary key,
 title varchar(50),
 dept_name varchar(20),
 credits numeric(2,0),
 foreign key (dept_name) references department) on delete cascade );

create table department (
dept_name varchar(20) primary key,
building varchar(20),
budget numeric(10,2) );


. student 테이블에 ID 는 “12345”, name 은 “홍길동”, dept_name 은 “Computer Engineering”, 
tot_cred는 120 인 학생 레코드를 insert하려고 한다. 이를 위하여 아래 JAVA 프로그램의
비어있는 부분을 답으로 제시하오. 단, insert 하려는 튜플(tuple, row, 행)의 속성(attribute, 열,
column) 값들은 프로그램 소스 코드 내에 기록하는 것으로 한다
import java.sql.*;
import java.sql.SQLException;
public class Test{
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		try {
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			String connectionUrl =
			"jdbc:sqlserver://localhost:49670;database=largeDB;integratedSecurity=true";
			Connection conn = DriverManager.getConnection(connectionUrl);
			PreparedStatement pStmt = …..
			…..
			…..
			pStmt.close(); 
			conn.close();
		} catch (ClassNotFoundException sqle) {
			System.out.println("SQLException : " + sqle);
		}
	}
}

conn.prepareStatement("insert into instructor values(?,?,?,?)");
pStmt.setString(1, "12345");
pStmt.setString(2, "홍길동");
pStmt.setString(3, "Computer Engineering");
pStmt.setInt(4, 120);
pStmt.executeUpdate();


테이블 R에 대하여 파악된 함수 종속(Functional-Dependency: FD) 집합 F의 규준 커버
(Canonical Cover) Fc
가 있다. Fc
를 근거로 하여 R이 BCNF가 되기 위한 조건을 제시하시오.
(Hint: F는 유추 가능한(inferable) FD들이 포함하고 있다.)

BCNF일 조건은 그 테이블에 정의되어진 함수적 종속성의 canonical cover 의 각각의 함수적 종속성의 결정자가 후보키면 된다.


테이블 R 의 스키마는 R(A, B, C, D, E, F, G, H) 이다. R에 대하여 파악한 함수 종속(FunctionalDependency: FD) 집합 F 는 아래와 같다. (Hint: F는 유추 가능한(inferable) FD들을 포함하고
있다.)
(A, B) -> C, D, E, G
B -> D, F, G, H
D -> F
R을 BCNF 조건을 만족하는 테이블 스키마들로 분해(Decomposition)한 결과를 제시하시오.
단, 분해한 테이블 스키마에서 주키(Primary Key)는 Underline(밑줄) 로 나타내시오.

(a,b,  c,e)
(b,    d,f,g,h)
*/

/*
. 본 문제에 국한하여 스키마 다이어그램의 advisor를 아래와 같이 변경한 것으로 한다. 즉,
(s_id, i_id)가 advisor 테이블의 주키(Primary Key)인 것으로 변경한다. i_id는 지도교수의 ID이
고 s_id는 지도학생의 ID이다. 이에 따라, advisor 테이블은 한 학생이 여러 교수들로부터
지도받고 한 교수가 여러 학생들을 지도하는 것을 표현한다.
이름이 ‘Einstein’ 인 교수와 이름이 ‘Srinivasan’ 인 교수가 함께 지도하고 있는 학생의 ID, 
name을 조회하는 SQL을 집합연산(Set Operation)을 이용하여 작성하시오. 단, from 절에
Cartesian Product(카티션 곱)를 사용하시오. from 절에 하위중첩 질의(Nested SQL)를 사용하지
마시오

(select student.ID, stduent.name
from student, instructor, advisor
where instructor.name='Einstein' and instructor.ID=advisor.i_id and advisor.s_id=student.ID)
intersect
(select student.ID, stduent.name
from student, instructor, advisor
where instructor.name='Srinivasan' and instructor.ID=advisor.i_id and advisor.s_id=student.ID)

*/
select distinct student.ID, student.name
from student, instructor, advisor 
where instructor.ID=advisor.i_id and 
	advisor.s_id=student.ID		
	and advisor.i_id in (select instructor.ID 
						from instructor 
						where instructor.name='Einstein') 
	and advisor.i_id in (select instructor.ID 
						from instructor 
						where instructor.name='Srinivasan')

/*
create view tot_credits(year, num_credits)
select year, sum(credits)
from course, takes
where course.course_id=takes.course_id
group by year
*/

select dept_name
from (select dept_name, sum(salary)
	  from instructor
	  group by dept_name) as dept_total (dept_name, sum_salary)
where sum_salary>=(select avg(sum_salary)
					from (select dept_name, sum(salary)
						  from instructor
						  group by dept_name) as dept_total (dept_name, sum_salary))

select avg(salary)
from instructor


select dept_name, budget
from department
where budget=(select max(budget)
			   from department)


with max_budget (value) as         
(select max(budget)           
from department)     
select dept_name, budget     
from department, max_budget     
where department.budget = max_budget.value;

select *
from department

select *
from (select dept_name, sum(salary)
     from instructor
     group by dept_name) as n(a,b)


(A, B) -> C, D, E, G
B -> D, F, G, H
D -> F

여기서

(A,B) -> S 로 치환
B -> Z로 치환

즉 B->Z인데 여기에 A를 붙이면 A,B->A, Z 라서 합치는거에요

with avg_salary(value) as
(select avg(salary)
 from instructor)
delete
from instructor
where salary<avg_salary.value

select dept_name, count(*),avg(salary)
from instructor I
where ID not in (select ID
                            from teaches T
                             where I.ID=T.ID)
group by dept_name

select dept_name, count(*),avg(salary)
from instructor I
where not exists (select ID
                              from teaches T
                              where I.ID=T.ID)
group by dept_name

select dept_name, count(student.ID) as cnt_st
from student left outer join takes on student.ID=takes.ID
where course_id is null
group by dept_name

select I.name, I.dept_name
from instructor I left outer join teaches T on T.ID = I.ID
where course_id is null

with avg_salary(value) as
(select avg(salary)
 from instructor)
delete
from instructor
where salary<avg_salary.value

select I.dept_name, avg(salary) as avg_salary
from instructor I, department D
where I.dept_name = D.dept_name and budget>all (select budget
                                                       from department
                                                         where building='Taylor')
group by I.dept_name

create view section_Taylor as
select *
from section
where building='Taylor'

select *
from section_Taylor
where year=2007 and semester='Spring'