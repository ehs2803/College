<%@ page language="java" contentType="text/html; charset=UTF-8"  pageEncoding="UTF-8" import="java.util.*, jspbook.contact.*"%>
<!DOCTYPE HTML>
<html>
<head>
<link rel="stylesheet" href="style.css" type="text/css" media="screen" />
<script type="text/javascript">
   function check(ab_id) {//id랑 update 눌렀을때,
      document.location.href="contact_control.jsp?action=edit&ct_id="+ab_id+"&upasswd="+"1234";//pwd
   }
   function delcheck(id) {
      result = confirm("정말로 삭제하시겠습니까 ?");
      if(result == true){
         document.location.href="update_contact_form.jsp?action=delete&ct_id="+id+"&upasswd="+"1234";//pwd
      }
      else
         return;
   }
</script>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>주소록:목록화면</title>
</head>
<jsp:useBean id="datas" scope="request" class="java.util.ArrayList" />
<body>
<div id="header">
<h2>2019305059 이현수</h2>
</div>
<br>
<button class="add-student-button" type="button" onclick="location.href='add_contact_form.jsp'">추가하기</button>
<div>
      <table>
         <tr>
           <th>first name</th>
           <th>last name</th>
           <th>email</th>
         </tr>
         <%--p.189~191 --%>
         <%
            for(Contact ab : (ArrayList<Contact>)datas) {
         %>
           <tr>
            <td><%=ab.getFirst_name() %></td>
            <td><%=ab.getLast_name() %></td>
            <td><%=ab.getEmail() %></td>
            <td><a href="javascript:check(<%=ab.getCt_id()%>)">update</a></td>
            <td><a href="javascript:delcheck(<%=ab.getCt_id()%>)">delete</a></td>
           </tr>
          <%
            }
          %>
      </table>
</div>
</body>
</html>