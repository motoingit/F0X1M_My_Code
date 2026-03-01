import java.util.Scanner;

class Bank {
    private static int nextAccNo = 1001;   // static for unique account numbers

    private String name;
    private String address;
    private int accountNumber;
    private double balance;

    // Constructor
    public Bank(String name, String address, double balance) {
        this.name = name;
        this.address = address;
        this.balance = balance;
        this.accountNumber = nextAccNo++;
    }

    // Display depositor info
    public void display() {
        System.out.println("Account Number : " + accountNumber);
        System.out.println("Name           : " + name);
        System.out.println("Address        : " + address);
        System.out.println("Balance        : " + balance);
    }

    // Deposit amount
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited Successfully !");
        }else{
            System.err.println("Wrong Amount !");
        }
    }

    // Withdraw amount
    public void withdraw(double amount) {
        if (balance - amount >= 0) {
            balance -= amount;
            System.out.println("Balance !");
        } else {
            System.out.println("Insufficient balance !");
        }
    }
    
    // Change address
    public void changeAddress(String newAddress) {
        address = newAddress;
        System.out.println("Adress Changed Sucessfully !");
    }

    public int getAccountNumber() {
        return accountNumber;
    }
}

public class j08_BankSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of depositors: ");
        int n = sc.nextInt();
        sc.nextLine();

        Bank[] accounts = new Bank[n];

        // Input depositor details
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for depositor " + (i + 1));
            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Address: ");
            String address = sc.nextLine();

            System.out.print("Initial Balance: ");
            double balance = sc.nextDouble();
            sc.nextLine();

            accounts[i] = new Bank(name, address, balance);
        }

        // Menu-driven operations
        System.out.println("BANK MENU:");
        System.out.println("1. Display account info");
        System.out.println("2. Deposit amount");
        System.out.println("3. Withdraw amount");
        System.out.println("4. Change address");
        System.out.println("5. Exit");

        int choice = -1;
        do {
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
        
            if (choice == 5) break;

            System.out.print("Enter account number: ");
            int accNo = sc.nextInt();
            sc.nextLine();

            Bank selected = null;
            for (Bank b : accounts) {
                if (b.getAccountNumber() == accNo) {
                    selected = b;
                    break;
                }
            }

            if (selected == null) {
                System.out.println("Account not found!");
                continue;
            }

            switch (choice) {
                case 1:
                    selected.display();
                    break;

                case 2:
                    System.out.print("Enter amount to deposit: ");
                    selected.deposit(sc.nextDouble());
                    selected.display();
                    break;

                case 3:
                    System.out.print("Enter amount to withdraw: ");
                    selected.withdraw(sc.nextDouble());
                    selected.display();
                    break;

                case 4:
                    System.out.print("Enter new address: ");
                    selected.changeAddress(sc.nextLine());
                    selected.display();
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice == 5);

        sc.close();
    }
}
