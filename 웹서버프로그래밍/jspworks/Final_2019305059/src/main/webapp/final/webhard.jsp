<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.sql.*"%>   
    
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <style>
        table  { width: 700px; text-align: center; }
        th     { background-color: cyan; }
        
        .left  { text-align: left;  }        
        .right { text-align: right; }

        a:link  { text-decoration: none; color: blue; }
        a:hover { text-decoration: none; color: red;  }
    </style>    
</head>
<body>

<form action="File_Upload_이현수.jsp" enctype="multipart/form-data" method="post">
    업로드할 파일을 선택하세요.<br>
    <input type="file" name="upload1"><br>
    <input type="file" name="upload2"><br>
    <input type="file" name="upload3"><br>
    <input type="submit" value="업로드">
</form>
<br>

<table>
    <tr>
        <th>파일명</th>
        <th>업로드 시간</th>
        <th>크기       </th>
        <th>삭제       </th>
        <th>파일다운</th>
    </tr>
    
<%  
   Connection conn = null;
   Statement stmt = null;

// 데이터베이스 연결관련정보를 문자열로 선언
    String jdbc_driver = "com.mysql.jdbc.Driver";
    String jdbc_url = "jdbc:mysql://127.0.0.1:3306/jspdb";
    
    
    try { 
        Class.forName(jdbc_driver);
    	conn = DriverManager.getConnection(jdbc_url,"root","1234");
        stmt = conn.createStatement();
            
        ResultSet rs = stmt.executeQuery("select * from webhard");
        {
            while (rs.next()) {
%>    
            <tr>
                <td class="left"><%=rs.getString("fname")%></td>
                <td><%=rs.getString("ftime")%></td>
                <td class="right"><%=rs.getInt("fsize")%>&nbsp;&nbsp;</td>
                <td><a href="del_file.jsp?num=<%=rs.getInt("num")%>" onclick="return confirm('Are you sure you want to delete this ?');">X</a></td>
            	<td class="left">
                    <a href="File_Download_이현수.jsp?fname=<%=rs.getString("fname")%>"><%=rs.getString("fname")%></a>
                </td>
            </tr>
<%  
            }
    } 
        }
    catch(Exception e) {
    e.printStackTrace();
    }
    
%>    
</table>
</body>
</html>
