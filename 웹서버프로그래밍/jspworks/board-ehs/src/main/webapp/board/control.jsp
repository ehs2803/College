<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" import="jspbook.board.*, java.util.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<% request.setCharacterEncoding("utf-8"); %>

<jsp:useBean id="ab" class="jspbook.board.BoardBean"/> 
<jsp:useBean id="addrbook" class="jspbook.board.Board"/>
<jsp:setProperty name="addrbook" property="*"/> 
<% 
	// 컨트롤러 요청 파라미터
	String action = request.getParameter("action");

	// 파라미터에 따른 요청 처리
	// 주소록 목록 요청인 경우

	if(action.equals("list")) {
		System.out.println("a");
		ArrayList<Board> datas = ab.getDBList();
		request.setAttribute("datas", datas);
		pageContext.forward("list.jsp");
	}
	// 주소록 등록 요청인 경우
	   else if(action.equals("insert")) {      
	      if(ab.insertDB(addrbook)) {
	         response.sendRedirect("control.jsp?action=list");
	      }
	      else
	         throw new Exception("DB 입력오류");
	   }
	   // 주소록 수정 페이지 요청인 경우
	   else if(action.equals("edit")) {
	      Board abook = ab.getDB(addrbook.getId());
	      //Board abook = ab.getDB(Integer.parseInt(request.getParameter("ct_id")));
	      
	      if(!request.getParameter("upasswd").equals("1234")) {
	         out.println("<script>alert('비밀번호가 틀렸습니다.!!');history.go(-1);</script>");
	      }
	      else {
	         request.setAttribute("ab",abook);
	         pageContext.forward("update.jsp");
	      }
	   }
	   // 주소록 수정 등록 요청인 경우
	   else if(action.equals("update")) {
	         if(ab.updateDB(addrbook)) {
	            response.sendRedirect("control.jsp?action=list");
	         }
	         else
	            throw new Exception("DB 갱신오류");
	   }
	   // 주소록 삭제 요청인 경우
	   else if(action.equals("delete")) {
	      System.out.println("test");
	      Board abook = ab.getDB(Integer.parseInt(request.getParameter("ct_id")));
	      String password = abook.getPassword();
	      if(request.getParameter("upasswd").equals(password)){
	         if(ab.deleteDB(Integer.parseInt(request.getParameter("ct_id")))) {
	            response.sendRedirect("control.jsp?action=list");
	         }
	         else
	            throw new Exception("DB 삭제 오류");
	      }
	      else{
	         out.println("<script>alert('action 파라미터를 확인해 주세요!!!')</script>");
	         response.sendRedirect("control.jsp?action=list");
	      }
	   }
	   else {
	      out.println("<script>alert('action 파라미터를 확인해 주세요!!!')</script>");
	      
	   }
	
	
%>