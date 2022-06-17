package jspbook.contact;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;


public class ContactBean { 
	
	Connection conn = null;
	PreparedStatement pstmt = null;
	
	/* MySQL 연결정보 */
	String jdbc_driver = "com.mysql.jdbc.Driver";
	String jdbc_url = "jdbc:mysql://127.0.0.1:3306/contact_tracker"; 
	
	// DB연결 메서드
	void connect() {
		try {
			Class.forName(jdbc_driver);

			conn = DriverManager.getConnection(jdbc_url,"jspbook","1234");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	void disconnect() {
		if(pstmt != null) {
			try {
				pstmt.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		} 
		if(conn != null) {
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
	
	// 수정된 주소록 내용 갱신을 위한 메서드
	public boolean updateDB(Contact addrbook) {
		connect();
		
		String sql ="update contact set first_name=?, last_name=?, email=? where id=?";		
		 
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,addrbook.getFirst_name());
			pstmt.setString(2,addrbook.getLast_name());
			pstmt.setString(3, addrbook.getEmail());
			pstmt.setInt(4,addrbook.getCt_id());
			pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
		finally {
			disconnect();
		}
		return true;
	}
	
	// 특정 주소록 게시글 삭제 메서드
	public boolean deleteDB(int gb_id) {
		connect();
		
		String sql ="delete from contact where id=?";
		
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1,gb_id);
			pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
		finally {
			disconnect();
		}
		return true;
	}
	
	// 신규 주소록 메시지 추가 메서드
	public boolean insertDB(Contact addrbook) {
		connect();
		// sql 문자열 , gb_id 는 자동 등록 되므로 입력하지 않는다.
				
		String sql ="insert into contact(first_name, last_name, email) values(?,?,?)";
		
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,addrbook.getFirst_name());
			pstmt.setString(2,addrbook.getLast_name());
			pstmt.setString(3, addrbook.getEmail());
			pstmt.executeUpdate();
		} catch (SQLException e) {
			e.printStackTrace();
			return false;
		}
		finally {
			disconnect();
		}
		return true;
	}

	// 특정 주소록 게시글 가져오는 메서드
	public Contact getDB(int gb_id) {
		connect();
		
		String sql = "select * from contact where id=?";
		Contact addrbook = new Contact();
		System.out.println(gb_id);
		
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1,gb_id);
			ResultSet rs = pstmt.executeQuery();
			
			// 데이터가 하나만 있으므로 rs.next()를 한번만 실행 한다.
			rs.next();
			addrbook.setCt_id(rs.getInt("id"));
			addrbook.setFirst_name(rs.getString("first_name"));
			addrbook.setLast_name(rs.getString("last_name"));
			addrbook.setEmail(rs.getString("email"));
			
			rs.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		finally {
			disconnect();
		}
		return addrbook;
	}
	
	// 전체 주소록 목록을 가져오는 메서드
	public ArrayList<Contact> getDBList() {
		connect();
		ArrayList<Contact> datas = new ArrayList<Contact>();
		
		String sql = "select * from contact order by id desc";
		try {
			pstmt = conn.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			while(rs.next()) {
				Contact addrbook = new Contact();
				
				addrbook.setCt_id(rs.getInt("id"));
				addrbook.setFirst_name(rs.getString("first_name"));
				addrbook.setLast_name(rs.getString("last_name"));
				addrbook.setEmail(rs.getString("email"));
				datas.add(addrbook);
			}
			rs.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		finally {
			disconnect();
		}
		return datas;
	}
}