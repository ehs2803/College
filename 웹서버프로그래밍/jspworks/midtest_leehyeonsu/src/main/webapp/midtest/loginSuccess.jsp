<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<%
	String name = request.getParameter("name");
String pwd = request.getParameter("pwd");
if(name.equals("jspbook") && pwd.equals("1234")){
	session.setAttribute("admin", name);
}
else{
	pageContext.forward("loginErr.jsp");
}

%>
<body>
<h1>Home -> 관리자화면</h1>

<hr>

새로운 세션이 생성되었습니다.
관리자 <%=session.getAttribute("admin") %>님이 입장했습니다.
<br>
<a href="memberList.jsp">등록회원관리화면으로</a>
<a href="logout.jsp">로그아웃하기</a>
</body>
</html>