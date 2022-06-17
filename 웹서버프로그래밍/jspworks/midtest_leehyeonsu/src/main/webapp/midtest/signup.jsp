<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<%
String action = request.getParameter("error");
if(action==null){
	
}
else if(action.equals("name")){
	out.println("<script>alert('아이디는 2~16글자')</script>");
}
else if(action.equals("pwd")){
	out.println("<script>alert('비밀번호는 6자리 이상!!')</script>");
}
else if(action.equals("email")){
	out.println("<script>alert('이메일은반드시 입력')</script>");
}


%>
<body>
<h1>Home -> 회원가입</h1>
<form name=form1 method=post action=insertDB.jsp>
<fieldset style="width:350px;"> 
<legend>개인 정보 입력</legend> 
<br>
아이디 : <br>
<input type="text" name="name"> <br><br>   <!-- text type input -->
비밀번호 : <br>
<input type="text" name="pwd"> <br><br>    <!-- text type input -->
이메일 :<br> 
<input type="email" name="email"> <br><br>   <!-- text type input -->
<hr>
<div align="center"><input type=reset value="다시작성"><input type=submit value="가입하기"> </div>
<br>
</fieldset>
</form>
</body>

</html>