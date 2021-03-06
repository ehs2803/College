import java.sql.*;
import java.sql.SQLException;
import java.util.Scanner;

public class prob1 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
    	Scanner sc = new Scanner(System.in);
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String connectionUrl = "jdbc:sqlserver://localhost:49672;database=largeDB;integratedSecurity=true";
            Connection conn = DriverManager.getConnection(connectionUrl);
            Statement stmt = conn.createStatement();
            
            System.out.print("교수 ID를 입력하세요: ");
            String id = sc.next();
            
            ResultSet rs = stmt.executeQuery("SELECT DISTINCT C.title\r\n"
            		+ "FROM teaches T, course C\r\n"
            		+ "WHERE T.ID="+id+" and T.course_id=C.course_id");      

            if(rs.next()) {
            	String field1 = rs.getString("title");
                System.out.println(field1);
            	while(rs.next()) {	
                    field1 = rs.getString("title");
                    System.out.println(field1);
               }
            }
            else {
            	System.out.println("맡은 강좌가 없음");
            }
            rs.close();
            stmt.close();   
            conn.close();
        } catch (ClassNotFoundException sqle) {
        	System.out.println("SQLException : " + sqle);
        }
        sc.close();
   }
}

/*
select title
from teaches T, section S, course C
where ID=14365 and T.course_id=S.course_id 
			and T.sec_id=S.sec_id 
			and T.semester=S.semester 
			and T.year=S.year 
			and S.course_id=C.course_id
*/