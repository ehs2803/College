<%@ page contentType="text/html; charset=utf-8" %>
<!DOCTYPE html>
<html>
<head>
<title>Hello</title>
</head>
<body>
<h1>LOGIN check</h1>
<%
	String id = (String)request.getAttribute("id");
	if(id!=null) out.println("<p> welcome "+id+"</p>");
	else out.println("login fail");
%>
</body>
</html>