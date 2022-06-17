package jspbook.board;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;

public class BoardBean { 
	
	Connection conn = null;
	PreparedStatement pstmt = null;
	
	/* MySQL 연결정보 */
	String jdbc_driver = "com.mysql.jdbc.Driver";
	String jdbc_url = "jdbc:mysql://127.0.0.1:3306/board_tracker"; 
	
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
	public boolean updateDB(Board addrbook) {
		connect();
		
		String sql ="update board set title=?, content=?, name=? where id=?";		
		 
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,addrbook.getTitle());
			pstmt.setString(2,addrbook.getContent());
			pstmt.setString(3, addrbook.getName());
			pstmt.setInt(4,addrbook.getId());
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
		
		String sql ="delete from board where id=?";
		
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
	public boolean insertDB(Board addrbook) {
		connect();
		// sql 문자열 , gb_id 는 자동 등록 되므로 입력하지 않는다.
				
		String sql ="insert into board(title,content,readcount,name,password,date) values(?,?,?,?,?,now())";
		//Timestamp reg_date=new Timestamp(System.currentTimeMillis());
		
		Date date = new Date();
		//SimpleDateFormat f = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss", Locale.KOREA);
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1,addrbook.getTitle());
			pstmt.setString(2,addrbook.getContent());
			pstmt.setInt(3, 0);
			//pstmt.setDate(4, now());
			pstmt.setString(4, addrbook.getName());
			pstmt.setString(5, addrbook.getPassword());
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
	public Board getDB(int gb_id) {
		connect();
		
		String sql = "select * from board where id=?";
		Board addrbook = new Board();
		System.out.println(gb_id);
		
		try {
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1,gb_id);
			ResultSet rs = pstmt.executeQuery();
			
			// 데이터가 하나만 있으므로 rs.next()를 한번만 실행 한다.
			rs.next();
			addrbook.setId(rs.getInt("id"));
			addrbook.setTitle(rs.getString("title"));
			addrbook.setContent(rs.getString("content"));
			addrbook.setReadcount(rs.getInt("readcount"));
			//addrbook.setDate(rs.getDate("date"));
			addrbook.setDate(rs.getDate("date")+" / "+rs.getTime("date"));
			addrbook.setName(rs.getString("name"));
			addrbook.setPassword(rs.getString("password"));
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
	public ArrayList<Board> getDBList() {
		connect();
		ArrayList<Board> datas = new ArrayList<Board>();
		
		String sql = "select * from board order by id desc";
		try {
			pstmt = conn.prepareStatement(sql);
			ResultSet rs = pstmt.executeQuery();
			while(rs.next()) {
				Board addrbook = new Board();
				
				addrbook.setId(rs.getInt("id"));
				addrbook.setTitle(rs.getString("title"));
				addrbook.setContent(rs.getString("content"));
				addrbook.setReadcount(rs.getInt("readcount"));
				addrbook.setDate(rs.getDate("date")+" / "+rs.getTime("date"));
				addrbook.setName(rs.getString("name"));
				addrbook.setPassword(rs.getString("password"));
				datas.add(addrbook);
			}
			rs.close();
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		finally {
			disconnect();
		}
		System.out.println(datas.size());
		return datas;
	}
}