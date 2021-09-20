import java.sql.*;
import java.util.Scanner;

public class prob2 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
    	Scanner sc = new Scanner(System.in);
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String connectionUrl = "jdbc:sqlserver://localhost:49670;database=largeDB;integratedSecurity=true";
            Connection conn = DriverManager.getConnection(connectionUrl);
            Statement stmt = conn.createStatement();
            
            System.out.print("학과명을 입력하세요: ");
            String dept = sc.nextLine();
            
            ResultSet rs = stmt.executeQuery("SELECT year, cnt FROM dept_section_cnt"
            		+" WHERE dept_name="+"'"+dept+"'");      

            if(rs.next()) {
            	String field1 = rs.getString(1);
            	String field2 = rs.getString(2);
                System.out.println(field1+" "+field2);
            	while(rs.next()) {	
            		field1 = rs.getString(1);
                	field2 = rs.getString(2);
                    System.out.println(field1+" "+field2);
               }
            }
            else {
            	System.out.println(dept+" 학과가 개설한 과목이 없습니다.");
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
select*
from dept_section_cnt
where dept_name='Biology'
*/