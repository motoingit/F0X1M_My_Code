package script;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class SetupDatabase {
    public static void main(String[] args) {
        // Change these to match your MySQL credentials
        String url = "jdbc:mysql://localhost:3306/"; 
        String user = "root"; 
        String password = "root@123"; 

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            // 1. Establish connection to MySQL server
            Connection conn = DriverManager.getConnection(url, user, password);
            Statement stmt = conn.createStatement();

            // 2. Create Database 
            stmt.execute("CREATE DATABASE IF NOT EXISTS studentdb");
            System.out.println("Database 'studentdb' created or already exists.");

            // 3. Select the Database 
            stmt.execute("USE studentdb");
            System.out.println("Switched to 'studentdb'.");

            // 4. Create the Table [cite: 34, 42]
            String createTableSql = "CREATE TABLE IF NOT EXISTS students ("
                                  + "id INT PRIMARY KEY AUTO_INCREMENT, "
                                  + "name VARCHAR(50), "
                                  + "age INT, "
                                  + "course VARCHAR(50))";
            stmt.execute(createTableSql);
            System.out.println("Table 'students' created successfully!");

            // Cleanup
            stmt.close();
            conn.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
