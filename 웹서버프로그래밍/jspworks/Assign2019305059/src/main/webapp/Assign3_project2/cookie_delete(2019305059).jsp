<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cookie Test-Delete Cookie</title>
</head>
<body>
<%
    // 전체 쿠키 삭제하기
    Cookie[] cookies = request.getCookies() ;   
    if(cookies != null){
        for(int i=0; i < cookies.length; i++){        
            // 쿠키의 유효시간을 0으로 설정하여 만료시킨다
            cookies[i].setMaxAge(0) ;    
            // 응답 헤더에 추가한다
            response.addCookie(cookies[i]) ;
        }
    }
%>

<!--  a태그를 통해 result파일로 이동해 쿠키가 삭제된 것을 확인한다. -->
쿠키가 삭제되었습니다 <a href="cookie_result(2019305059).jsp">쿠키 삭제 확인</a>
</body>
</html>