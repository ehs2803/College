import java.awt.*;
import javax.swing.*;

public class ch9_2 extends JFrame{
	public ch9_2() {
		setTitle("BorderLayout");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		c.setLayout(new BorderLayout(5,7));
		c.add(new JButton("north"), BorderLayout.NORTH);
		c.add(new JButton("west"), BorderLayout.WEST);
		c.add(new JButton("center"), BorderLayout.CENTER);
		c.add(new JButton("east"), BorderLayout.EAST);
		c.add(new JButton("south"), BorderLayout.SOUTH);
		
		setSize(400,200);
		setVisible(true);
	}
	public static void main(String [] args) {
		new ch9_2();
	}
}