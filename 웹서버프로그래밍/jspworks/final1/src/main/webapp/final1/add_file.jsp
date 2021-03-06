<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<%@ page import="com.oreilly.servlet.MultipartRequest,
                 com.oreilly.servlet.multipart.DefaultFileRenamePolicy,
                 java.io.File" %>
<%@ page import="java.time.*" %>

<%
    MultipartRequest multi = new MultipartRequest(
            request,
            application.getRealPath("/final1/files"),   // 파일을 저장할 경로
            100 * 1024 * 1024,                   // 최대 파일 크기 (100MB)
            "utf-8",                             // 인코딩
            new DefaultFileRenamePolicy()        // 동일 파일명 처리 방법
    );

    File file1 = multi.getFile("upload1");         // 파일 객체 얻기
	File file2 = multi.getFile("upload2");
    File file3 = multi.getFile("upload3");
    
    String name1 = multi.getParameter("name1");
    String name2 = multi.getParameter("name2");
    String name3 = multi.getParameter("name3");
    
    Connection conn = null;
    Statement stmt = null;

 // 데이터베이스 연결관련정보를 문자열로 선언
     String jdbc_driver = "com.mysql.jdbc.Driver";
     String jdbc_url = "jdbc:mysql://127.0.0.1:3306/jspdb";
    if (file1 != null && file2!=null && file3!=null) {
        
        try {
        Class.forName(jdbc_driver);
        conn = DriverManager.getConnection(jdbc_url,"root","1234");
                stmt = conn.createStatement();
         {
            // 현재 시간 얻기
            String curTime = LocalDate.now() + " " +
                             LocalTime.now().toString().substring(0, 8);
            
            

            // 쿼리 실행
            stmt.executeUpdate(String.format(
                "insert into webhard (fname, ftime, fsize, username) " +
                "values ('%s', '%s', %d, '%s')",
                file1.getName(), curTime, (int)file1.length(), name1));
            
            stmt.executeUpdate(String.format(
                    "insert into webhard (fname, ftime, fsize, username) " +
                    "values ('%s', '%s', %d, '%s')",
                    file2.getName(), curTime, (int)file2.length(), name2));
            
            stmt.executeUpdate(String.format(
                    "insert into webhard (fname, ftime, fsize, username) " +
                    "values ('%s', '%s', %d, '%s')",
                    file3.getName(), curTime, (int)file3.length(), name3));

            // 메인 페이지로 돌아가기
            response.sendRedirect("webhard.jsp");
            return;

        } 
        }
         catch(Exception e) {
            e.printStackTrace();
        }
    }

%>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>

<script>
    alert('업로드 실패 !');
    history.back();
</script>

</body>
</html>