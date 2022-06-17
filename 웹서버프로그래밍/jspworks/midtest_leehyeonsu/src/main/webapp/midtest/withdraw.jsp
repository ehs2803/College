<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h1>Home -> 회원 탈퇴하기</h1>
<hr>

<form name=form1 method=post action=deleteDB.jsp>
<fieldset style="width:350px;"> 
<legend>회원탈퇴</legend> 
<br>

아이디 : <br>
<input type="text" name="name"> <br><br>   <!-- text type input -->


<div align="center"><input type=submit value="회원탈퇴"> </div>
<br>
</fieldset>
</form>

</body>
</html>