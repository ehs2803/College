<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.contact.*"%>
<!DOCTYPE HTML>
<html>
<head>
<link rel="stylesheet" href="add-student-style.css" type="text/css" media="screen" />
<link rel="stylesheet" href="style.css" type="text/css" media="screen" />
<script>
function delcheck(id) {
	document.location.href="contact_control.jsp?action=delete&ct_id="+id+"&upasswd="+"1234";
}
</script>
<% 
String action = request.getParameter("action");
if(action.equals("delete")){
	String id = request.getParameter("ct_id"); String pwd = request.getParameter("upasswd");
	out.println(String.format("<script>delcheck(%s)</script>", id));
}
%>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>주소록:수정화면</title>
</head>
<jsp:useBean id="ab" scope="request" class="jspbook.contact.Contact" />
<body>
<div id="wrapper">
<div id="header">
<h2><%=ab.getFirst_name() %><%=ab.getLast_name() %>_Email_<%=ab.getEmail() %></h2>
</div>
<div id="container">
<h3>정보 갱신</h3>
<div id="content">
<form name=form1 method=post action=contact_control.jsp>
<input type=hidden name="ct_id" value="<%=ab.getCt_id()%>">
<input type=hidden name="action" value="update">
<table border="1">
<tr><label for="n">first name:
    <input type="text" name="first_name" id="n" value="<%=ab.getFirst_name() %>"></label><br></tr>
<tr><label for="ln">last name:
    <input type="text" name="last_name" id="ln" value="<%=ab.getLast_name() %>"></label><br></tr>
<tr><label for="e">email:
    <input type="email" name="email" id="e" value="<%=ab.getEmail() %>"></label></tr>
  <tr>
    <input class="save" type=submit value="저장">
  </tr>
</table>
</form>
<br><br><br><br>
<a href=contact_control.jsp?action=list>Back to List</a>
</div>
</div>
</div>
</body>
</html>