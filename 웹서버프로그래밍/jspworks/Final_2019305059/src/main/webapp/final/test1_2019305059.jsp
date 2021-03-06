<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="final1.BookBean"  %>
<%@ page import="java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	List<BookBean> bookList = new ArrayList<BookBean>();
    bookList.add(new BookBean("미드나잇라이브러리","매크 헤이그","인플루엔셜"));
    bookList.add(new BookBean("자바 웹 프로그래밍","황희정","한빛아카데미"));

	String []bookCode = {"소설","역사","인문","정치","미술","종교","여행","과학","만화","건강"};
	
	String []colors = {"Red","Green","Blue","Black"};
	
	String BookCode1 = "소설/역사/인문/정치/미술/종료/여행/과학/만화/건강";
	
	pageContext.setAttribute("bookList",bookList);
	pageContext.setAttribute("bookCode",bookCode);
	pageContext.setAttribute("colors",colors);
	pageContext.setAttribute("BookCode1", BookCode1);
%>

2019305059 이현수 
<br><br>

<c:forEach var="book" items="${bookList}">
	${book.title}/${book.author}/${book.publisher}<br>
</c:forEach>
<hr>

<c:forEach var="code" items="${bookCode}">
	<c:out value="${code}"/>
</c:forEach>
<hr>

JSTL를 이용한 출력 <br><br>

<c:forEach var="colorsel" items="${colors}">
    <font color="${colorsel}">${colorsel}</font>
</c:forEach>

<br><br>

varStatus 속성 살펴보기<br><br>
<table border="1">
<c:forEach var="i" varStatus="status" begin="3" end="5">
    <tr>
    	<td>count : ${status.count}</td>
    	<td>index : ${status.index}</td>
    </tr>
</c:forEach>
</table>
<br>

1에서 100까지 정수 중 홀수의 합(step 사용 금지)<br>
<%! int sum=0; %>
<c:set value="0" var="summ"/>
<c:forEach var="i" varStatus="status" begin="1" end="100">
    <c:if test="${status.index%2==1 }" var="result">
	<c:set value="${status.index}" var="summ"/>
	 <% 
	 int a = Integer.parseInt(pageContext.getAttribute("summ").toString()); 
	 sum+=a;
	 %>
    </c:if>
</c:forEach>
<br>

1~100 사이의 정수 중 홀수의 합은? <% out.println(sum); %>
<br><br>

<c:forTokens items="${BookCode1}" delims="/" var="code">
	${code}
</c:forTokens>

</body>
</html>