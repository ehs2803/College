<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<link rel="stylesheet" href="add-student-style.css" type="text/css" media="screen" />
<link rel="stylesheet" href="style.css" type="text/css" media="screen" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>주소록:작성화면</title>

</head>
<body>

<div id="wrapper">

<div id="header">
<h2>2019305059 이현수</h2>
</div>

<div id="container">
<h3>contact 추가</h3>

<div id="content">

<form name=form1 method=post action=contact_control.jsp>
<input type=hidden name="action" value="insert">
<table>
	<tr><label for="n">first name:
    <input type="text" name="first_name" id="n"></label><br></tr>
	<tr><label for="ln">last name:
    <input type="text" name="last_name" id="ln" ></label><br></tr>
	<tr><label for="e">email:
    <input type="email" name="email" id="e" ></label></tr>
</table>
<input class="save" type=submit value="저장">
</form>
<br>
<br><br>
<br>
<a href=contact_control.jsp?action=list>목록으로</a>

</div>
</div>
</div>
</body>
</html>