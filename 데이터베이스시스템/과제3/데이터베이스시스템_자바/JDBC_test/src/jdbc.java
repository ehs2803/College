import java.sql.*;
import java.sql.SQLException;
import java.util.Scanner;

public class jdbc {

    public static void main(String[] args) throws ClassNotFoundException, SQLException {
    	Scanner sc = new Scanner(System.in);
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String connectionUrl = "jdbc:sqlserver://localhost:49670;database=largeDB;integratedSecurity=true";
            Connection conn = DriverManager.getConnection(connectionUrl);
            Statement stmt = conn.createStatement();
            
            System.out.print("교수 ID를 입력하세요: ");
            int id = Integer.parseInt(sc.next());
            
            ResultSet rs = stmt.executeQuery("SELECT * FROM instructor");
            while( rs.next() ) {
                   String field1 = rs.getString("name");
                   String field2 = rs.getString("dept_name");
                   String field3 = rs.getString(3);
                   System.out.print(field1 + "\t");
                   System.out.print(field2 + "\t");
                   System.out.println(field3 );
                  }
            rs.close();
            stmt.close();   
            conn.close();
        } catch (ClassNotFoundException sqle) {
        	System.out.println("SQLException : " + sqle);
        }
   }
}