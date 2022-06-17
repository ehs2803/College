<%@ page language="java" contentType="text/html; charset=UTF-8" %>

<html>
	<HEAD><TITLE>request 객체</TITLE><HEAD/>
	<BODY>
		<table border=1>
			<tr>
				<td><b> client & server information </b><td>
				<td><b> 값 </b><td>
			</tr>
			<tr>
				<%
					out.println("<tr><td>인코딩 방식</td><td>+request.getCharacterEncodint() + "</td></tr>");
					out.println("<tr><td>mime 타입</td><td>+request.getContentType() + "</td></tr>");	
					out.println("<tr><td>요청 정보 길이</td><td>+request.getContentLength() + "</td></tr>");
					out.println("<tr><td>header 이름</td><td>+request.getHeaderName() + "</td></tr>");
					out.println("<tr><td>웹 전달 경로</td><td>+request.getPathInfo() + "</td></tr>");
					out.println("<tr><td>클라이언트 이름</td><td>+request.getRemoteHost() + "</td></tr>");
					out.println("<tr><td>클라이언트 ip주소</td><td>+request.getRemoteAddr() + "</td></tr>");
					out.println("<tr><td>클라이언트 url 경로</td><td>+request.getRequestURL() + "</td></tr>");
					out.println("<tr><td>전송 방식</td><td>+request.getMethod() + "</td></tr>");
					out.println("<tr><td>프로토콜 이름</td><td>+request.getProtocol() + "</td></tr>");
					out.println("<tr><td>서버 이름</td><td>+request.getServerName() + "</td></tr>");
					out.println("<tr><td>서버 포트번호</td><td>+request.getServerPort() + "</td></tr>");			
				%>
			</tr>
		</table>
	</BODY>
</html>