<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1>관리자 로그아웃</h1>
<% session.invalidate(); %>
<hr>
관리자 로그아웃

<a href="main.jsp">메인화면으로</a>
</body>
</html>