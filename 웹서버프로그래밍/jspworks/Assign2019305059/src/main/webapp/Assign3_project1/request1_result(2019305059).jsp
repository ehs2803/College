<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>정보확인</title>
</head>
<body>
<h3>Home > 입력 정보 확인 </h2>
<hr>
이름 : 
<!-- getParameter메서드를 통해 "name"로 설정된 form의 text 값 읽어옴 -->
<%=request.getParameter("name")%> <br><br>

비밀번호 : 
<!-- getParameter메서드를 통해 "pwd"로 설정된 form의 text 값 읽어옴 -->
<%=request.getParameter("pwd")%> <br><br>

E-mail : 
<!-- getParameter메서드를 통해 "mail"로 설정된 form의 text 값 읽어옴 -->
<%=request.getParameter("mail")%> <br><br>

연락처 : 
<!-- getParameter메서드를 통해 company의 값, phone1,phone2,phone3로 설정된 form의 text 값 읽어옴 -->
<%=request.getParameter("company")%> 
<%=request.getParameter("phone1")%>-
<%=request.getParameter("phone2")%>-
<%=request.getParameter("phone3")%> <br><br>

성별 : 
<!-- getParameter메서드를 통해 "gender"로 설정된 form의 radio 값 읽어옴 -->
<%=request.getParameter("gender")%> <br><br>

취미 : 
<%
	// getParameterValues 메서드를 이용해 "favorite" 로 설정된 form 의 체크박스 값들을 모두 읽어옴.
	String favorites[] = request.getParameterValues("favorite");
	// 배열의 크기만큼 루프롤 돌면서 값을 출력함.
	if(favorites==null){ // null일 경우. 값 선택 안한경우
		out.println("없음");
	}
	else{
		for(int i=0; i<favorites.length;i++) { // 출력 
			out.println(favorites[i]+" ");
		}
	}

%>
<br><br>
본인 소개 : 
<!-- getParameter메서드를 통해 "self"로 설정된 form의 textarea 값 읽어옴 -->
<%=request.getParameter("self")%> <br><br>
</body>
</html>