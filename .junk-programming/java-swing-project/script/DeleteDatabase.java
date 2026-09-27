package script;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class DeleteDatabase {

    private static final String URL = "jdbc:mysql://localhost:3306/";
    private static final String USER = "root";
    private static final String PASSWORD = "root@123";

    public static void main(String[] args) {

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection connection = DriverManager.getConnection(
                    URL,
                    USER,
                    PASSWORD
            );

            Statement statement = connection.createStatement();

            statement.execute(
                    "DROP DATABASE IF EXISTS studentdb"
            );

            System.out.println("Database deleted successfully.");

            statement.close();
            connection.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
