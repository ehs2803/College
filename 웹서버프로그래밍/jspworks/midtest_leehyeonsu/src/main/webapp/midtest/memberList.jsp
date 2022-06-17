<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.sql.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<% request.setCharacterEncoding("utf-8"); %>
<%
   
	// 데이터베이스 연결관련 변수 선언
	Connection conn = null;
	PreparedStatement pstmt = null;

	// 데이터베이스 연결관련정보를 문자열로 선언
	String jdbc_driver = "com.mysql.jdbc.Driver";
	String jdbc_url = "jdbc:mysql://127.0.0.1/jspdb";
	try{
		// JDBC 드라이버 로드
		Class.forName(jdbc_driver);
		// 데이터베이스 연결정보를 이용해 Connection 인스턴스 확보
		conn = DriverManager.getConnection(jdbc_url,"jspbook","1234");
		// Connection 클래스의 인스턴스로 부터 SQL  문 작성을 위한 Statement 준비
		String sql = "select * from midtest";
		pstmt = conn.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		int cnt=0;
		while(rs.next()) {
			cnt++;
			String name = rs.getString("id");
			String email = rs.getString("email");
			Timestamp time = rs.getTimestamp("signuptime");
			out.println(cnt+": "+name+"/"+email+"/"+time+"<br>");
		}
		rs.close();
		
		
		pstmt.close();
		conn.close();
	}
	catch(Exception e) {	
		System.out.println(e);
	}
%>
<hr>
<a href="withdraw.jsp">회원탈퇴시키기</a>
<a href="logout.jsp">로그아웃하기</a>