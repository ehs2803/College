<%@ page language="java" contentType="text/html; charset=euc-kr" %>

<HTML>
	<BODY>
		<%
			String id = (String)session.getAttribute("ID");
			out.println(id+"님 안녕하세요.");
			session.invalidate();
		%>
	</BODY>
</HTML