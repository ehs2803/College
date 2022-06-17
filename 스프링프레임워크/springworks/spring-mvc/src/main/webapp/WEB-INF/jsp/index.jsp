<%@ page language="java" contentType="text/html; charset=EUC-KR" pageEncoding="EUC-KR"%>
<%@ page import="java.util.Date,java.text.SimpleDateFormat" %>
<!DOCTYPE html>
<html>
<head>  <meta charset="EUC-KR"> </head>
<body>
<h1> Index Page </h1> 
<%=new SimpleDateFormat("yyyy년MM월dd일").format(new Date()) %>
</body>
</html>   