import java.sql.*;
import java.util.Scanner;

public class prob4 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
    	Scanner sc = new Scanner(System.in);
    	try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String connectionUrl = "jdbc:sqlserver://localhost:49670;database=largeDB;integratedSecurity=true";
            Connection conn = DriverManager.getConnection(connectionUrl);
            CallableStatement cstmt = null;
            System.out.print("교수명을 입력하세요: ");
            String name = sc.nextLine();
            try {
            	cstmt = conn.prepareCall("{? = call dbo.inst_advise_student (?)}");
                cstmt.registerOutParameter(1,java.sql.Types.VARCHAR); 
                cstmt.setString(2, name);
                cstmt.execute();
                String outParam = cstmt.getString(1);
                System.out.println("교수 "+name+"가 지도하는 학생수는 "+outParam+"명 입니다.");
            }
            catch(Exception e) {
            	System.out.println("Exception message: "+e.getMessage());
            }
            cstmt.close();
            conn.close();
        } catch (ClassNotFoundException sqle) {
        	System.out.println("SQLException : " + sqle);
        }
    	sc.close();
   }
}
