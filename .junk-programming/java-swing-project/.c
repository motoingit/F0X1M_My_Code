// wrong
cd "E:\xGarageX\JdbcSwingProject\"
javac -cp .;lib/mysql-connector-j-9.7.0.jar -d bin src\Main.java
java -cp bin;lib/mysql-connector-j-9.7.0.jar Main

// right
javac -cp ".;lib\mysql-connector-j-9.7.0.jar" -d bin src\Main.java
java -cp "bin;lib\mysql-connector-j-9.7.0.jar" Main

// 
javac -cp ".;lib/mysql-connector-j-9.7.0.jar script\TestDriver.java"
java -cp ".;lib/mysql-connector-j-9.7.0.jar script.TestDriver"
