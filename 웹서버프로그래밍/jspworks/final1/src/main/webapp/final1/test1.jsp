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
	//List<BookBean> books = new ArrayList<BookBean>();
	//books.add(new BookBean("미드나잇라이브러리","매크헤이그","인플루엔셜"));
	//books.add(new BookBean("자바웹프로그래밍","황희정","한빛아카데미"));

	//String []strs = {"소설","역사","인문","정치","미술","종교","여행","과학","만화","건강"};
	
	//pageContext.setAttribute("books",books);
	//pageContext.setAttribute("strs",strs);
%>

<c:forEach var="book" items="${books}">
	${book.title}/${book.author}/${book.publisher}<br>
</c:forEach>
<hr>

<c:forEach var="str" items="${strs}">
	<c:out value="${str}"/>
</c:forEach>
<br>
<hr>

<c:forEach var="i" begin="2" end="9">
	<c:forEach var="j" begin="1" end="9">
		${i}*${j} = ${i*j} <br>
	</c:forEach>
	<br>
</c:forEach>

<c:forTokens items="소설/역사/인문/정치/미술/종료/여행/과학/만화/건강" delims="/" var="sel">
	${sel}
</c:forTokens>

</body>
</html>