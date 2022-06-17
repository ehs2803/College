<%@page import="java.net.URLDecoder"%> <!-- URLDecoder를 사용하기 위한 선언 -->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cookie Test-Get Cookie</title>
</head>
<body>

<%  
    // 쿠키 불러오기  
	Cookie cookies[] = request.getCookies();
	//length==1을 한 이유는 톰캣 컨테이너에서 세션을 유지하기 위해 발급하는 키 JESSIONID가 쿠키로 들어가기 때문에 
	// 즉 사용자가 생성한 쿠키를 삭제하면 1개는 무조건 남아있게 되있음.
	if(cookies.length==1){ // 쿠키가 없다면 
		out.println("저장된 쿠키가 없습니다."); // 해당문장 출력 
	}
	else{ // 저장된 쿠키가 있다면 저장된 쿠키 출력
		// length-1을 한 이유는 톰캣 컨테이너에서 세션을 유지하기 위해 발급하는 키 JESSIONID가 쿠키로 들어가기 때문에 
		// 사용자가 생성한 쿠키만 출력하기 위함이다. 
		for(int i=0;i<cookies.length-1;i++){
			out.println(cookies[i].getName()+" 은 <strong>"+URLDecoder.decode(cookies[i].getValue(), "UTF-8")+"</strong>입니다.<br>");
		}
	}
%>

</body>
</html>