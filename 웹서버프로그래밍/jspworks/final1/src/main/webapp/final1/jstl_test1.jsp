/*
JSTL은 자바의 기능을 태그 스타일로 구현해서 쓸수 있게 해주는 요소들을 뜻합니다.
간단히 말해서 복잡하게 자바나 JSP 전체 문장을 쓰지 않고 <tag>tag</tag> 형태로 바꾼 것을 뜻합니다.
MyBatis와 유사하게 JSTL을 쓰면 라이브러리로 자바 구문을 만들어놓고 필요할 때마다 꺼내쓰면 되기 때문에 유지보수에 편리하다는 장점이 있습니다.

파일은 tutorial과 test, exam 폴더로 이뤄져 있으면 여기서는 exam 폴더의 일부 코드만을 올립니다.
자세한 것은 Github를 참고하여 주시기 바랍니다.







<▼시작▼ | 파일명 : jstl_ex1.jsp >

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>* JSTL TEST *</title>
</head>
<body>
<h2>* JSTL TEST *</h2>
--- 변수 선언 ---<br>
<c:set var="ir" value="홍길동" scope="page"/> <!--  자바 객체는 value에 다 들어올 수 있음 / request,page,session,application -->
<c:out value="${ir}"/><br>
\${ir} ==> ${ir}
<br><hr>
<c:set var="ir2" scope="session">
한국인
</c:set>
<c:out value="${ir2}"/>
<br><hr>
<c:set var="aa" value="${header['User-Agent']}" scope="page"/>
USER-AGENT 값은 : <c:out value="${aa}"/>
<br>
<c:remove var="aa" scope="page"/> <!-- remove는 삭제한다는 의미 -->
aa 삭제 후 값은 >>[ <c:out value="${aa}"/> ] >> 변수값이 삭제됨
<br>
<c:set var="su1" value="10"/>
<c:set var="su2" value="${20}"/>
<c:set var="su3">
30.5
</c:set>
합은 ${su1 + su2 + su3}<br>
</body>
</html>

<▲종료 ▲ | 파일명 : jstl_ex1.jsp >



<▼시작▼ | 파일명 : jstl_ex2.jsp >

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>* JSTL TEST2 *</title>
</head>
<body>
<h2> * JSTL TEST2 *</h2>
-- 제어문 : 조건 판단 --
<c:set var="kbs" value="moon"/>
<c:if test="${kbs == 'star'}">
if 연습 : kbs 값은 <c:out value="${kbs}"/> <!-- KBS가 STAR라는 조건에 부합할 경우에 출력 -->
</c:if>
<br>
<c:if test="${kbs eq 'moon'}">
if 연습 : 아하 달이네  <!-- 13번 줄의 value 값에 달라서 출력 유무 결정 -->
</c:if>

<p>
choose 문 사용(if ~else는 choose로 표현)<br>
<c:choose>
     <c:when test="${kbs =='star'}">별</c:when>
     <c:when test="${kbs =='moon'}">달</c:when>
     <c:otherwise>어떤 조건도 아닐 경우 수행</c:otherwise>
</c:choose>
<br>
<c:choose>
     <c:when test="${empty param.name}">
     <form>
     이름 : <input type="text" name="name">
          <input type="submit" value="확인">
     </form>
     </c:when>
     <c:when test="${param.name == 'admin' }">
          관리자 작업
     </c:when>
     <c:when test="${param.name eq 'user' }">
          일반 사용자. 회원 <c:out value="${param.name}" />
     </c:when>
          <c:otherwise>
              기타 작업
          </c:otherwise>
</c:choose>

</p>
</body>
</html>

<▲종료 ▲ | 파일명 : jstl_ex2.jsp >



<▼시작▼ | 파일명 : jstl_ex3.jsp >

<%@page import="java.util.Date"%>
<%@page import="java.util.HashMap"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>제어문, 반복문 JSTL TEST</title>
</head>
<body>
<h2> 제어문, 반복문 JSTL TEST</h2>
forEach 연습 결과
<c:forEach var="i" begin="1" end="10" step="1"> <!-- 증가치가 1일 경우 생략 -->
     <c:out value="${i}" /> &nbsp;&nbsp;
</c:forEach>
<br>
문제 ) 구구단 3단 출력
<c:forEach var="i" begin="1" end="9" step="1">
     3 * ${i} = ${3 * i}<br> 
</c:forEach>
<p/>
forEach 결과 (header:내장객체(k,v)):<br>
<c:forEach var="h" items="${headerValues}"> <!-- 헤더값을 찍음 -->
     속성 : <c:out value="${h.key}" /> &nbsp;&nbsp;
     값 : <c:forEach var="k" items="${h.value }">
          <c:out value="${k}"/>
          </c:forEach>
          <hr>
</c:forEach>
<br><br>
<%
HashMap map = new HashMap();
map.put("name", "홍길동");
map.put("today", new Date());
%>

<c:set var="arr" value="<%= new int[]{1,2,3,4,5} %>"/>
<c:set var="m" value="<%=map %>"/>
배열 출력 <br>
<c:forEach var="i" items="${arr}" begin="0" end="5" step="1">
${i} &nbsp;&nbsp;
</c:forEach>
<br>
map 출력<br>
<c:forEach var="i" items="${m}">
     ${i.key}:${i.value}<br>
</c:forEach>
</body>
</html>

<▲종료▲ | 파일명 : jstl_ex3.jsp >



<▼시작▼ | 파일명 : jstl_ex4.jsp >

<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
   
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>** 문자열 분할 JSTL TEST **</title>
</head>
<body>
<h2>** 문자열 분할 JSTL TEST ** </h2>
<c:forTokens var="ani" items="horse,tiger,lion" delims=",">
동물: <c:out value="${ani}"/><br>
</c:forTokens>

<p/>
--- 숫자 및 날짜 서식 ---
<%@ taglib prefix ="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %><br>
숫자 : <fmt:formatNumber value="98745612345.678" type="number"/><br>
통화 : <fmt:formatNumber value="12345.789" type="currency" currencySymbol="$"/><br>
숫자 : <fmt:formatNumber value="12345.456" pattern="#,##0.0"/><br>
<c:set var="kor" value="77" />
<c:set var="eng" value="88" />
<c:set var="mat" value="91" />
다 합해서 나누기 3 : <fmt:formatNumber value="${(kor + eng + mat) / 3}" pattern="##0.0"/>
<br>
<hr>
<c:set var="now" value="<%=new Date() %>" />
${now}
<br>
날짜 : <fmt:formatDate value="${now}" type="date"/><br>
시간 : <fmt:formatDate value="${now}" type="time"/><br>
날짜 : <fmt:formatDate value="${now}" type="both" dateStyle="full"/>


</body>
</html>

<▲종료▲ | 파일명 : jstl_ex4 .jsp >



<▼시작▼ | 파일명 : jstl7_sql.jsp >

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
    <%@ taglib prefix="sql" uri="http://java.sun.com/jsp/jstl/sql" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
JSTL로 db 자료 읽기(상품)<p/>
<c:catch var="err">
<sql:setDataSource
var = "ds"
url="jdbc:mysql://localhost:3306/test"
driver="org.mariadb.jdbc.Driver"
user="root"
password="123"
/>
<sql:query var="rs" dataSource="${ds}">
select * from sangdata where code >= ? and code <= ?
<sql:param value="${1}"/>
<sql:param value="5" />
</sql:query>

<table border="1">
     <tr>
     <th>code</th><th>sang</th><th>su</th><th>dan</th>
     <c:forEach var="s" items="${rs.rows}">
     <tr>
          <td>${s.code}</td>
          <td>${s.sang}</td>
          <td>${s.su}</td>
          <td>${s.dan}</td>
     </tr>
     </c:forEach>
     </tr>

</table>


</c:catch>
<c:if test="%{err !=null}">
     에러 : ${err.message}
</c:if>
</body>
</html>

<▲종료▲ | 파일명 : jstl7_sql.jsp >
출처: https://note.espriter.net/1179 [espriter:티스토리]
*/