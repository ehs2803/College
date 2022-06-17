<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.*, java.text.*, jspbook.board.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<script type="text/javascript">
   function check(ab_id) {//id랑 update 눌렀을때,
     
      document.location.href="control.jsp?action=edit&id="+ab_id+"&upasswd="+"1234";//pwd
   }
   function delcheck(id) {
      result = confirm("정말로 삭제하시겠습니까 ?");

      if(result == true){
    	  pwd = prompt('수정/삭제 하려면 비밀번호를 넣으세요');
         document.location.href="control.jsp?action=delete&ct_id="+id+"&upasswd="+pwd;//pwd
         
      }
      else
         return;
   }
</script>
<jsp:useBean id="datas" scope="request" class="java.util.ArrayList" />
<body>
<button class="add-student-button" type="button" onclick="location.href='add.jsp'">추가</button>
<div>

      <table>
         <tr>
           <th>번호</th>
           <th>제목</th>
           <th>name</th>
           <th>작성날짜</th>
         </tr>
         <%--p.189~191 --%>
         <%
            for(Board ab : (ArrayList<Board>)datas) {
         %>
           <tr>
            <td><%=ab.getId()%></td>
            <td><%=ab.getTitle() %></td>
            <td><%=ab.getName() %></td>
            <td><%=ab.getDate() %></td>
            <td><a href="javascript:check(<%=ab.getId()%>)">update</a></td>
            <td><a href="javascript:delcheck(<%=ab.getId()%>)">delete</a></td>
           </tr>
          <%
            }
          %>
      </table>


</div>

</body>
</html>