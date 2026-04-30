// Vowel COunt

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class j23 extends JFrame implements ActionListener {

    private JTextField inputField, resultField;
    private JButton countBtn, resetBtn, exitBtn;

    public j23() {
        setTitle("Vowel Counter");
        setSize(400, 250);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Input
        add(new JLabel("Enter String:"));
        inputField = new JTextField(20);
        add(inputField);

        // Result
        add(new JLabel("Vowel Count:"));
        resultField = new JTextField(10);
        resultField.setEditable(false);
        add(resultField);

        // Buttons
        countBtn = new JButton("CountVowel");
        resetBtn = new JButton("Reset");
        exitBtn = new JButton("Exit");

        // Set commands
        countBtn.setActionCommand("COUNT");
        resetBtn.setActionCommand("RESET");
        exitBtn.setActionCommand("EXIT");

        // ONE listener
        countBtn.addActionListener(this);
        resetBtn.addActionListener(this);
        exitBtn.addActionListener(this);

        add(countBtn);
        add(resetBtn);
        add(exitBtn);

        setVisible(true);
    }

    // 🔥 One method handles all buttons
    @Override
    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();

        switch (cmd) {

            case "COUNT":
                String text = inputField.getText().toLowerCase();
                
                int count = 0;
                for (char c : text.toCharArray()) {
                    if ("aeiou".indexOf(c) != -1) {
                        count++;
                    }
                }

                resultField.setText(String.valueOf(count));
                break;

            case "RESET":
                inputField.setText("");
                resultField.setText("");
                break;

            case "EXIT":
                System.exit(0);
                break;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new j23());
    }
}
