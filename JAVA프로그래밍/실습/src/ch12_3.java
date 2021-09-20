import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch12_3 extends JFrame {
	public ch12_3(){
		super("�̹��� ���̺� �巡�� ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);
		
		ImageIcon icon = new ImageIcon("images/backiee-89981.jpg"); // �̹��� �ε�		
		JLabel imageLabel = new JLabel(icon); // �̹��� ���̺� �����
	
		// �̹��� ���̺��� ũ��� ��ġ ����
		//imageLabel.setSize(icon.getIconHeight(),icon.getIconWidth());
		imageLabel.setSize(50,50);
		imageLabel.setLocation(100,100);
		
		// ���콺 �����ʿ� ���콺��� ������ ��ü �ޱ�
		MyMouseListener_ch12_3  ml = new MyMouseListener_ch12_3();
		imageLabel.addMouseListener(ml);
		imageLabel.addMouseMotionListener(ml);

		c.add(imageLabel); // ����Ʈ�ҿ� �̹��� ���̺� ����
		setSize(300,300);
		setVisible(true);
	}
	
	class MyMouseListener_ch12_3 extends MouseAdapter {
		private Point startP = null; // �巡�� ���� ��
		
		@Override
		public void mousePressed(MouseEvent e) {
			startP = e.getPoint();
		}
		
		// ���� mouseReleased()�� ����� �Ǵ� �ڵ���.
		// ������ �ǽ����� 4�� Ǯ�� ���ؼ��� �ݵ��  mouseReleased()�� �����Ͽ��� ��
		@Override
		public void mouseReleased(MouseEvent e) {
			Point endP = e.getPoint();
			Component la = (JComponent)(e.getSource());
			Point p = la.getLocation();
			la.setLocation(p.x + endP.x - startP.x, p.y + endP.y - startP.y);
			la.getParent().repaint(); // ������ la�� ��ġ�� �ٽ� �׸���
		}	
		
		@Override
		public void mouseDragged(MouseEvent e) {
			Point endP = e.getPoint();
			Component la = (JComponent)(e.getSource());
			Point p = la.getLocation();
			la.setLocation(p.x + endP.x - startP.x, p.y + endP.y - startP.y);
			la.getParent().repaint(); // ������ la�� ��ġ�� �ٽ� �׸���
		}	
	}
	
	static public void main(String[] args) {
		new ch12_3();
	}
}