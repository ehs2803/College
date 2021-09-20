import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch10_2 extends JFrame{
	Container c = getContentPane();
	public ch10_2() {
		super("µå·¡±ëµ¿¾È YELLOW");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		c.setBackground(Color.GREEN);
		c.addMouseListener(new MyMouseListener());
		c.addMouseMotionListener(new MyMouseMotionListener());

		setSize(400,200);
		setVisible(true);
	}
	class MyMouseListener extends MouseAdapter {
		public void mouseReleased(MouseEvent e) {
			c.setBackground(Color.GREEN);
		}
	}
	
	class MyMouseMotionListener extends MouseMotionAdapter{
		public void mouseDragged(MouseEvent e) {
			c.setBackground(Color.YELLOW);
		}
	}
	public static void main(String [] args) {
		new ch10_2();
	}
}
//20210507