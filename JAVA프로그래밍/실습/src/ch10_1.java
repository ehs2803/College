import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ch10_1 extends JFrame{
	public ch10_1() {
		super("���콺 �ø��� ������");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
        c.setLayout(new FlowLayout());
		
		JLabel label = new JLabel("Love Java");
		c.add(label); // ����Ʈ�ҿ� ���̱�
		
		label.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseEntered(MouseEvent e) {
				JLabel la = (JLabel)e.getSource();
				la.setText("Love Java");
			}
			@Override
			public void mouseExited(MouseEvent e) {
				JLabel la = (JLabel)e.getSource();
				la.setText("�����");
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