<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.board.*"%>
<!DOCTYPE HTML>
<html>
<head>


<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>주소록:수정화면</title>
</head>

<jsp:useBean id="ab" scope="request" class="jspbook.board.Board" />

<body>

<div id="wrapper">
<div id="header">
<h2>2019305059 이현수</h2>
</div>

<div id="container">
<h3>contact 추가</h3>

<div id="content">

<form name=form1 method=post action=control.jsp>
<input type=hidden name="id" value="<%=ab.getId()%>">
<input type=hidden name="action" value="update">

<table>
<tr><label for="n">content:
    <input type="text" name="title" id="n" value="<%=ab.getTitle() %>"></label><br></tr>
<tr><label for="ln">title:
    <input type="text" name="content" id="ln" value="<%=ab.getContent() %>"></label><br></tr>
<tr><label for="e">pw:
    <input type="text" name="name" id="e" value="<%=ab.getName() %>"></label></tr>

  <tr>
    <input class="save" type=submit value="저장">
  </tr>
</table>
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