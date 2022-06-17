<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<HTML>
	<HEAD> 
		<TITLE> request 객체 </TITLE>
	</HEAD>
	<BODY>
		<%
			String ID = request.getParameter("strID");
			String pass = request.getParameter("strPwd");

			out.println("아이디 : " + ID + "<BR>");
			out.println("비밀번호 : " + pass);
		%>
	</BODY>
</HTML>