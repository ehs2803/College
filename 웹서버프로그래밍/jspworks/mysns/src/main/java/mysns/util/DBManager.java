package mysns.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.Statement;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

/**
 * File : DBManager.java
 * Desc : 데이터베이스 연결 처리 클래스
 * @author 황희정(dinfree@dinfree.com)
 * 
 */
public class DBManager {
	// 데이터베이스 관련 객체 선언
	Statement stmt = null;
	PreparedStatement pstmt = null;
	
	/**
	 * JNDI 를 이용해 Connection 객체 리턴
	 * @return
	 */
	public static Connection getConnection() {
		Connection conn;
		try {
			/* MySQL 연결정보 */
			String jdbc_driver = "com.mysql.jdbc.Driver";
			String jdbc_url = "jdbc:mysql://127.0.0.1:3306/jspdb"; 
			Class.forName(jdbc_driver);

			conn = DriverManager.getConnection(jdbc_url,"jspbook","1234");
			
			//Context initContext = new InitialContext();
			//Context envContext = (Context) initContext.lookup("java:/comp/env");
			//DataSource ds = (DataSource) envContext.lookup("jdbc/mysql");
			//conn = ds.getConnection();
		}
		catch (Exception e) {
			System.out.println(e);
			e.printStackTrace();
			return null;
		}
		return conn;
	}
}