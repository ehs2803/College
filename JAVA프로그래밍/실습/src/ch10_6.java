import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch10_6 extends JFrame{
	public ch10_6() {
		super("클릭 연습 용 응용프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);
		
		JLabel label = new JLabel("C");
		label.setLocation(100,100);
		label.setSize(20,20);
		c.add(label);
		
		label.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				JLabel la = (JLabel)e.getSource();
				int x = (int) (Math.random() * 300);
				int y = (int) (Math.random() * 300);
				la.setLocation(x, y);
			}
		});
		
		setSize(500,500);
		setVisible(true);
	}
	public static void main(String [] args) {
		new ch10_6();
	}
}
//20210507