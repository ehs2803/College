<%@page import="java.net.URLEncoder"%> <!-- URLEncoder를 사용하기 위한 선언 -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta charset="UTF-8">
<title>Cookie Test-Set Cookie</title>
</head>
<body>
<%
    // 쿠키 생성1
    String name = URLEncoder.encode("HyeonSu Lee", "UTF-8"); // 쿠키에 공백문자를 넣기 위한 코드 
    Cookie c1 = new Cookie("name", name); 
    response.addCookie(c1);
    // 쿠키 생성2
    Cookie c2 = new Cookie("mail", "hr2803@naver.com"); 
    response.addCookie(c2);
%>
<div align=center> <!-- align=center를 통해 가운데 정렬 -->
<h1>쿠키 테스트</h1>
쿠키 설정이 완료되었습니다.<br><br>

<!-- a태그를 통해 이동할 파일 지정. -->
<a href="cookie_result(2019305059).jsp">쿠키보기</a> <a href="cookie_delete(2019305059).jsp">쿠키삭제</a>
</div>

</body>
</html>