<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<HTML>
<HEAD>
<title>ch06 : selProduct.jsp</title>
</head>
<%
	request.setCharacterEncoding("UTF-8"); // euc-kr
	session.setAttribute("username",request.getParameter("username"));
%>
<body>
<div align="center">
	<H2>상품선택</H2>
	<HR>
	<%=session.getAttribute("username") %>님 환영합니다!!!!
	<HR>
	<form name="form1" method="POST" action="add.jsp">
		<SELECT name="product">
			<option>사과</option>    <!-- 100원 -->
			<option>귤</option>     <!-- 200원 -->
			<option>파인애플</option> <!-- 300원 -->
			<option>자몽</option>    <!-- 400원 -->
			<option>레몬</option>    <!-- 500원 -->
		</SELECT>
		<input type="submit" value="추가"/>
	</form>
	<a href="checkOut_2019305059.jsp">계산</a>
</div>
</body>
</html>




