<%@ page contentType="text/html; charset=utf-8" %>
<!DOCTYPE html>
<html>
<head>
<title>Hello</title>
</head>
<body>
<h1>LOGIN</h1>
<form action="/logincheck" method="GET">
	<input type="text" name="id"/>
	<input type="text" name="pwd"/>
	<input type="submit" value="login"/>
</form>
</body>
</html>