<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>2019305059 이현수</title>
<style>
	.tel{
		width:50px;
	}
</style>
</head>
<body>
<h3>Home > 회원 정보 입력 </h2>
<hr>
<form name=form1 method=get action=request1_result(2019305059).jsp> <!-- get방식으로 처리 -->
<fieldset style="width:350px;"> <!-- form 테두리 설정 -->
<legend>개인 정보 입력</legend> <!-- fieldset 제목 붙이기 -->
<br>
이름 : <br>
<input type="text" name="name"> <br><br>   <!-- text type input -->
비밀번호 : <br>
<input type="text" name="pwd"> <br><br>    <!-- text type input -->
E-mail :<br> 
<input type="text" name="mail"> <br><br>   <!-- text type input -->
연락처 :<br>
<select name="company">  <!-- select option으로 사용자가 선택가능 -->
	<option value="none">선택</option>
	<option value="KT">KT</option>
	<option value="SKT">SKT</option>
	<option value="LGU+">LGU+</option>
	<option value="자급제">자급제</option>
</select>
<input type="text" class="tel" name="phone1"> -     <!-- text type input + "tel"class적용해 width값 css적용 -->
<input type="text" class="tel" name="phone2"> -     <!-- text type input + "tel"class적용해 width값 css적용 -->
<input type="text" class="tel" name="phone3"> <br><br><!-- text type input + "tel"class적용해 width값 css적용 -->
성별 :
<input type="radio" name="gender" value="남성">남          <!-- radio type input-->
<input type="radio" name="gender" value="여성">여 <br><br> <!-- radio type input-->
취미 :
<input type=checkbox name=favorite value="운동">운동  <!-- checkbox type input-->
<input type=checkbox name=favorite value="독서">독서  <!-- checkbox type input-->
<input type=checkbox name=favorite value="여행">여행  <!-- checkbox type input-->
<input type=checkbox name=favorite value="음악감상">음악감상 <br><br>  <!-- checkbox type input-->
본인 소개 : <br>
<textarea rows="5" cols="45" name="self"></textarea><br><!-- textarea type input + rows, cols 값 지정으로 너비,높이 설정-->
<hr>
<!-- align="center"로 가운데 정렬 + type submit input과 type reset input 적용 -->
<div align="center"><input type=submit value="가입하기"> <input type=reset value="다시작성"></div>
<br>
</fieldset>
</form>
</body>
</html>