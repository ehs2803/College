import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class ch12_8 extends JFrame{
	private Vector<Circle> circle = new Vector<Circle>();
	public ch12_8() {
		super("���콺�� �� �׸���");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new MyPanel_ch12_8());
		setSize(500, 300);
		setVisible(true);
	}
	class Circle { // ���� ǥ���ϴ� Circle Ŭ����
		int x; // ���� x��ǥ
		int y; // ���� y��ǥ
		int d; // ���� ����

		public Circle(int xPosition, int yPosition, int diameter) {
			x = xPosition;
			y = yPosition;
			d = diameter;
		}
	}

	class MyMouseListener extends MouseAdapter {
		private int startX;
		private int startY;
		private int endX;
		private int endY;

		public void mousePressed(MouseEvent e) {
			Point startP = e.getPoint(); // ���� �߽�
			startX = (int) startP.getX();
			startY = (int) startP.getY();
		}

		public void mouseReleased(MouseEvent e) {
			Point endP = e.getPoint();
			endX = (int) endP.getX();
			endY = (int) endP.getY();

			int disX = endX - startX; // �߽����κ��� �巡���� ������ x��ǥ ����
			int disY = endY - startY; // �߽����κ��� �巡���� ������ y��ǥ ����
			int radius = (int) Math.sqrt(disX * disX + disY * disY); // ������ ���ϱ�
			Circle c = new Circle(startX - radius, startY - radius, 2 * radius);
			circle.add(c); // ���Ϳ� �߰�
			repaint();
		}
	}

	class MyPanel_ch12_8 extends JPanel {
		public MyPanel_ch12_8() {
			setFocusable(true);
			requestFocus();
			addMouseListener(new MyMouseListener());
		}

		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.setColor(Color.MAGENTA);
			for (int i = 0; i < circle.size(); i++) {
				Circle c = circle.elementAt(i);
				g.drawOval(c.x, c.y, c.d, c.d);
				// (x,y) ��ġ���� �����ϰ� �Ѻ� ���̰� c.d�� ���簢���� �����ϴ� ���� �׸�
			}
		}
	}

	public static void main(String[] args) {
		new ch12_8();
	}
}
