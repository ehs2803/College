import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ch10_1 extends JFrame{
	public ch10_1() {
		super("마우스 올리기 내리기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
        c.setLayout(new FlowLayout());
		
		JLabel label = new JLabel("Love Java");
		c.add(label); // 컨텐트팬에 붙이기
		
		label.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				JLabel la = (JLabel)e.getSource();
				la.setText("Love Java");
			}
			@Override
			public void mouseExited(MouseEvent e) {
				JLabel la = (JLabel)e.getSource();
				la.setText("사랑해");
			}			
		});
		setSize(400,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch10_1();
	}
}
//20210507