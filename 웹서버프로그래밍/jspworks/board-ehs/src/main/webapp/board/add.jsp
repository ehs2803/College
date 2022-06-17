<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>주소록:작성화면</title>

</head>
<body>

<div id="wrapper">

<div id="header">
<h2>2019305059 이현수</h2>
</div>

<div id="container">
<h3>추가</h3>

<div id="content">

<form name=form1 method=post action=control.jsp>
<input type=hidden name="action" value="insert">
<table>
	<tr><label for="n">title:
    <input type="text" name="title" id="n"></label><br></tr>
    
	<tr><label for="ln">content:
    <input type="text" name="content" id="ln" ></label><br></tr>
    
	<tr><label for="ee">name:
    <input type="text" name="name" id="ee" ></label></tr>
    
    <tr><label for="eee">password:
    <input type="text" name="password" id="eee" ></label></tr>
    
</table>
<input class="save" type=submit value="저장">
</form>
<br>
<br><br>
<br>
<a href=control.jsp?action=list>주소록 목록으로</a>

</div>
</div>
</div>
</body>
</html>