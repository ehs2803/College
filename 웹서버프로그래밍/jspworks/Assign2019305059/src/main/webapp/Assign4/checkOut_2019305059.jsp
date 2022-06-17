<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<HTML>
<HEAD>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>2019305059 이현수</title>
</HEAD>
<body>
<div align="center">
<H2>계산</H2>
선택한 상품 목록
<HR>
<%
	ArrayList list = (ArrayList)session.getAttribute("productlist");
	if(list == null) { // 리스트가 비어있다면 
		out.println("선택한 상품이 없습니다.!!!");
	}
	else { // 리스트가 비어있지 않다면 
	    int totalCnt=0, totalPrice=0;
	    HashMap<String, Integer> map = new HashMap<>(); // 각 상품별 개수 저장하기 위한 map
	    
		for(Object productname:list) { 
			totalCnt++; // 상품 개수 변수 1 증가 
			// 각 상품별 가격을 totalPrice에 저장 
			if(productname.equals("사과")) totalPrice+=100; 
			else if(productname.equals("귤")) totalPrice+=200;
			else if(productname.equals("파인애플")) totalPrice+=300;
			else if(productname.equals("자몽")) totalPrice+=400;
			else if(productname.equals("레몬")) totalPrice+=500;
			
			if(map.get(productname)==null){ // 처음 등장하는 상품일 경우 
				map.put(productname.toString(), new Integer(1)); // map에 value로 1 저장 
			}
			else{ // 이미 map에 있는 key, 상품인 경우 
				int num = map.get(productname); // value 얻어오기 
				map.put(productname.toString(), num+1); // value값에 1증가해서 map에 저장 
			}
		}
		
		for(Map.Entry<String, Integer> entry : map.entrySet()){ // for문으로 map 순회 
			String name = entry.getKey(); // 상품 이름 저장 변수 
			int cnt = entry.getValue(); // 특정 상품 주문 개수 저장 변수 
			int price =0; // 특정 상품의 총 가격 저장 변수 
			int itemPrice=0; // 특정 상품 가격 
			if(name.equals("사과")) { // 사과일 경우 - 100원
				price = cnt*100;
				itemPrice=100;
			}
			else if(name.equals("귤")){ // 귤일 경우 - 200원
				price = cnt*200;
				itemPrice=200;
			}
			else if(name.equals("파인애플")) { // 파인애플일 경우 - 300원
				price = cnt*300;
				itemPrice=300;
			}
			else if(name.equals("자몽")) { // 자몽일 경우 - 400원
				price = cnt*400;
				itemPrice=400;
			}
			else if(name.equals("레몬")) { // 레몬일 경우 - 500원
				price = cnt*500;
				itemPrice=500;
			}
			
			out.println(name+"("+itemPrice+"원)"+" : " +cnt+"개 : "+price+"원<BR>"); // 각 상품 별 이름, 주문개수, 총가격 출력 
		}
		out.println("<BR><BR>선택한 상품의 총 개수 : "+ totalCnt+"개<BR>"); // 선택 상품 총 개수 출력 
		out.println("선택한 상품의 총 금액 : "+ totalPrice+"원<BR>"); // 선택 상품 총 금액 출력 
	}
%>
</div>
</body>
</html>