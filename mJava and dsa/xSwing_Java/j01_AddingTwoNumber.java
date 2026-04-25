/* Ques:  TypeHere */

import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

class Graphic extends JFrame{
   Graphic(String name){
      super(name);
                     //Setting Window
      setSize(500, 500);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setLayout(null);
                     //Adding Components
      // Label 1
      JLabel label1 = new JLabel("Num1:");
      label1.setBounds(100, 100, 60, 25);
      add(label1);

      // TextField 1
      JTextField textField1 = new JTextField();
      textField1.setBounds(170, 100, 120, 25);
      add(textField1);

      // Label 2
      JLabel label2 = new JLabel("Num2:");
      label2.setBounds(100, 160, 60, 25);
      add(label2);

      // TextField 2
      JTextField textField2 = new JTextField();
      textField2.setBounds(170, 160, 120, 25);
      add(textField2);

      // Button
      JButton button1 = new JButton("Add");
      button1.setBounds(100, 230, 80, 30);
      add(button1);

      // Result Area
      JTextArea textArea0 = new JTextArea();
      textArea0.setBounds(200, 230, 100, 40);
      textArea0.setEditable(false);
      add(textArea0);

      // Button
      JButton button0 = new JButton("Exit");
      button0.setBounds(100, 330, 80, 30);
      add(button0);

               //adding eventListner
      
      button1.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e){
            // tryCatch ?
            int num1 = Integer.parseInt(textField1.getText());
            int num2 = Integer.parseInt(textField2.getText());
            Integer sum = num1+num2;
            textArea0.setText((sum.toString()));
         }
      });

      button0.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e){
            System.exit(JFrame.EXIT_ON_CLOSE);
         }
      });

      setVisible(true);
   }
}

public class j01_AddingTwoNumber{
   public static void main(String[] args) {
      Graphic frame = new Graphic("MyApplication");
   }
}
