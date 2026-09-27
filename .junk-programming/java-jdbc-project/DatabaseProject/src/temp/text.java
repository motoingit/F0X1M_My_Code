//try {
//    // 1. Loading the driver (Optional in newer JDBC but recommended for verification)
//    Class.forName("com.mysql.cj.jdbc.Driver");
//
//    // 2. Establish Connection
//    Connection con = DriverManager.getConnection(url, user, password);
//    System.out.println("✅ Connected Successfully!\n");
//
//} catch (ClassNotFoundException e) {
//    // Specific error if the Connector/J JAR is missing from the Build Path
//    System.err.println("❌ JDBC Driver not found: " + e.getMessage());
//
//} catch (SQLException e) {
//    // Specific error for database issues (wrong password, server down, etc.)
//    System.err.println("❌ Database connection error: " + e.getMessage());
//    System.err.println("SQL State: " + e.getSQLState());
//    System.err.println("Error Code: " + e.getErrorCode());
//
//} catch (Exception e) {
//    // Catch-all for any other unexpected logic errors
//    System.err.println("❌ An unexpected error occurred: " + e.getMessage());
//}