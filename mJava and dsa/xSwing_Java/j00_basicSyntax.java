import java.awt.FlowLayout;
import javax.swing.*; //for tools
// import java.awt.*; //for layout

class sample extends JFrame{
    sample(String name){
        super(name);

        //* Frame Set */
        this.setSize(500, 500);                // width, height in pixels
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // close button works
        // frame.setDefaultCloseOperation(JFrame.ABORT)
        this.setLayout(new FlowLayout()); //* 5dir layout */

        //*adding component */
        // JLabel
        JLabel label = new JLabel("This is Label");
        this.add(label);

        // JButton
        JButton btn = new JButton("Click Me");
        this.add(btn);

        // JTextField
        JTextField tf = new JTextField(20); // visiable size
        this.add(tf);


        this.setVisible(true);                 // show window
    }
}

public class j00_basicSyntax{
    public static void main(String[] args) {
        sample frame = new sample("My App");
    }
}

/* NOTE:
    - add() order matters
    -
*/
