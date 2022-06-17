<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<%



%>
<body>
<h1>Home ->관리자 로그인</h1>
<form name=form1 method=post action=loginSuccess.jsp>
<fieldset style="width:350px;"> 
<legend>개인 정보 입력</legend> 
<br>
아이디 : <br>
<input type="text" name="name"> <br><br>   <!-- text type input -->
비밀번호 : <br>
<input type="text" name="pwd"> <br><br>    <!-- text type input -->

<div align="center"><input type=submit value="관리자 로그인"> </div>
<br>
</fieldset>
</form>
</body>

</html>