public import javax.swing.*;
import java.awt.event.*;

class Graphic extends JFrame {

    private JTextField textField1;
    private JTextField textField2;
    private JTextArea resultArea;

    public Graphic(String title) {
        super(title);

        // Frame setup
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);

        // Label 1
        JLabel label1 = new JLabel("Num1:");
        label1.setBounds(100, 100, 60, 25);
        add(label1);

        // TextField 1
        textField1 = new JTextField();
        textField1.setBounds(170, 100, 120, 25);
        add(textField1);

        // Label 2
        JLabel label2 = new JLabel("Num2:");
        label2.setBounds(100, 160, 60, 25);
        add(label2);

        // TextField 2
        textField2 = new JTextField();
        textField2.setBounds(170, 160, 120, 25);
        add(textField2);

        // Button
        JButton addButton = new JButton("Add");
        addButton.setBounds(100, 230, 80, 30);
        add(addButton);

        // Result Area
        resultArea = new JTextArea();
        resultArea.setBounds(200, 230, 100, 40);
        resultArea.setEditable(false);
        add(resultArea);

        // Event Handling (Lambda)
        addButton.addActionListener(e -> calculateSum());

        setVisible(true);
    }

    // Business Logic (clean separation)
    private void calculateSum() {
        try {
            int num1 = Integer.parseInt(textField1.getText().trim());
            int num2 = Integer.parseInt(textField2.getText().trim());

            int sum = num1 + num2;
            resultArea.setText(String.valueOf(sum));

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this,
                    "Please enter valid integers",
                    "Input Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}

public class j01_second {
    public static void main(String[] args) {

        // Run on EDT (important)
        SwingUtilities.invokeLater(() -> {
            new Graphic("My Application");
        });
    }
}
