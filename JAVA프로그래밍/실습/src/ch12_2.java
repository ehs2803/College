import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ch12_2 extends JFrame{
	public ch12_2() {
		super("이미지 위에 드래깅 연습");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new MyPanel_ch12_2());
		setSize(400,400);
		setVisible(true);
	}
	
	class MyPanel_ch12_2 extends JPanel{
		private ImageIcon icon = new ImageIcon("images/backiee-36622.jpg");
		private Image img = icon.getImage();
		private Point point = new Point(50,50);
		public MyPanel_ch12_2() {
			this.addMouseMotionListener(new MouseMotionAdapter() {
				public void mouseDragged(MouseEvent e) {
					point = e.getPoint();
					repaint();
				}
			});
		}
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), this);
			g.setColor(Color.GREEN);
			g.fillOval((int)point.getX(), (int)point.getY(), 40, 40);
		}
	}
	public static void main(String [] args) {
		new ch12_2();
	}
}
