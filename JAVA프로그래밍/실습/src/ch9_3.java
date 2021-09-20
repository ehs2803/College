import java.awt.*;
import javax.swing.*;

public class ch9_3 extends JFrame {
	public ch9_3() {
		super("Ten Color Buttons Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		c.setLayout(new GridLayout());
		c.add(new JButton("0"));
		c.add(new JButton("1"));
		c.add(new JButton("2"));
		c.add(new JButton("3"));
		c.add(new JButton("4"));
		c.add(new JButton("5"));
		c.add(new JButton("6"));
		c.add(new JButton("7"));
		c.add(new JButton("8"));
		c.add(new JButton("9"));
		
		setSize(800,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch9_3();
	}
}
//20210505