import java.sql.*;
import java.util.Scanner;

public class Main {

    static final String URL = "jdbc:mysql://localhost:3306/studentdb";
    static final String USER = "root";
    static final String PASSWORD = "root@123";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n=============================");
            System.out.println("     STUDENT MANAGEMENT      ");
            System.out.println("=============================");
            System.out.println("1. Add Student");
            System.out.println("2. View All Students");
            System.out.println("3. Delete Student by ID");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");

            String choice = scanner.nextLine().trim();

            switch (choice) {
                case "1" -> addStudent(scanner);
                case "2" -> viewStudents();
                case "3" -> deleteStudent(scanner);
                case "4" -> {
                    System.out.println("Goodbye!");
                    scanner.close();
                    System.exit(0);
                }
                default -> System.out.println("Invalid option. Try again.");
            }
        }
    }

    static void addStudent(Scanner scanner) {
        System.out.print("Enter Name   : ");
        String name = scanner.nextLine().trim();

        System.out.print("Enter Age    : ");
        String ageInput = scanner.nextLine().trim();

        System.out.print("Enter Course : ");
        String course = scanner.nextLine().trim();

        try {
            int age = Integer.parseInt(ageInput);
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(URL, USER, PASSWORD);

            String query = "INSERT INTO students (name, age, course) VALUES (?, ?, ?)";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, name);
            ps.setInt(2, age);
            ps.setString(3, course);
            ps.executeUpdate();

            System.out.println("Student added successfully!");
            ps.close();
            con.close();

        } catch (NumberFormatException e) {
            System.out.println("Invalid age. Please enter a number.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void viewStudents() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(URL, USER, PASSWORD);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM students");

            System.out.println("\n------------------------------------------------------------");
            System.out.printf("%-5s %-20s %-5s %-20s%n", "ID", "Name", "Age", "Course");
            System.out.println("------------------------------------------------------------");

            boolean hasData = false;
            while (rs.next()) {
                hasData = true;
                System.out.printf("%-5d %-20s %-5d %-20s%n",
                    rs.getInt("id"),
                    rs.getString("name"),
                    rs.getInt("age"),
                    rs.getString("course"));
            }

            if (!hasData) {
                System.out.println("No students found.");
            }

            System.out.println("------------------------------------------------------------");
            rs.close();
            stmt.close();
            con.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void deleteStudent(Scanner scanner) {
        viewStudents();
        System.out.print("Enter Student ID to delete: ");
        String idInput = scanner.nextLine().trim();

        try {
            int id = Integer.parseInt(idInput);
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(URL, USER, PASSWORD);

            PreparedStatement ps = con.prepareStatement("DELETE FROM students WHERE id = ?");
            ps.setInt(1, id);
            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("Student deleted successfully!");
            } else {
                System.out.println("No student found with ID " + id);
            }

            ps.close();
            con.close();

        } catch (NumberFormatException e) {
            System.out.println("Invalid ID.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
