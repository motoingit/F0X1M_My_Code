/* Ques: P-23 Swing */

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

class Graphic extends JFrame implements ActionListener{
   JTextField inputString;
   JTextField outputNumber;
   JButton reset, count;

   Graphic(String appName){
      super(appName);

      //layout
      setTitle("Vovel Counter");
      setSize(500,500);
      setLayout(new FlowLayout());
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      //Components
      add(new JLabel("Input String : "));
      inputString = new JTextField("Enter Here");
      add(inputString);

      add(new JLabel("Count : "));
      outputNumber = new JTextField("No Data");
      outputNumber.setEditable(false);
      add(outputNumber);

      reset = new JButton("reset");
      count = new JButton("count");
      add(reset);
      add(count);

      //butns command
      count.setActionCommand("COUNT");
      reset.setActionCommand("RESET");
      // ONE listener
      count.addActionListener(this);
      reset.addActionListener(this);

      setVisible(true);
   }

   //* Funtiong of  */
   @Override
   public void actionPerformed(ActionEvent e){
      String cmd = e.getActionCommand();

         switch (cmd) {
            case "COUNT":
               String text = inputString.getText().toLowerCase();
               int count = 0;
               for (char c : text.toCharArray()) {
                  if ("aeiou".indexOf(c) != -1) {
                     count++;
                  }
               }
               outputNumber.setText(String.valueOf(count));
               break;

            case "RESET":
               inputString.setText("Enter String");
               outputNumber.setText("No Data");
               break;

            default:
               outputNumber.setText("Wrong Button");
      }
   }
}

public class j23{
   public static void main(String[] args) {
      Graphic test = new Graphic("MOto");
   }
}
