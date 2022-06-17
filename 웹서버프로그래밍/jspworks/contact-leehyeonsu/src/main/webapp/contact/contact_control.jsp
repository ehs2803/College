<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" import="jspbook.contact.*, java.util.*"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<% request.setCharacterEncoding("utf-8"); %>
<jsp:useBean id="ab" class="jspbook.contact.ContactBean"/> 
<jsp:useBean id="addrbook" class="jspbook.contact.Contact"/>
<jsp:setProperty name="addrbook" property="*"/> 
<% 
	String action = request.getParameter("action");
	if(action.equals("list")) {
		ArrayList<Contact> datas = ab.getDBList();
		request.setAttribute("datas", datas);
		pageContext.forward("list_contact_all.jsp");
	}
	// 주소록 등록 요청인 경우
	else if(action.equals("insert")) {		
		if(ab.insertDB(addrbook)) {
			response.sendRedirect("contact_control.jsp?action=list");
		}
		else
			throw new Exception("DB 입력오류");
	}
	// 주소록 수정 페이지 요청인 경우
	else if(action.equals("edit")) {
		Contact abook = ab.getDB(addrbook.getCt_id());
		if(!request.getParameter("upasswd").equals("1234")) {
			out.println("<script>alert('비밀번호가 틀렸습니다.!!');history.go(-1);</script>");
		}
		else {
			request.setAttribute("ab",abook);
			pageContext.forward("update_contact_form.jsp");
		}
	}
	// 주소록 수정 등록 요청인 경우
	else if(action.equals("update")) {
			if(ab.updateDB(addrbook)) {
				response.sendRedirect("contact_control.jsp?action=list");
			}
			else
				throw new Exception("DB 갱신오류");
	}
	// 주소록 삭제 요청인 경우
	else if(action.equals("delete")) {
		if(ab.deleteDB(addrbook.getCt_id())) {
			response.sendRedirect("contact_control.jsp?action=list");
		}
		else
			throw new Exception("DB 삭제 오류");
	}
	else {
		out.println("<script>alert('action 파라미터를 확인해 주세요!!!')</script>");
	}
%>