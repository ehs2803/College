import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ch12_4 extends JFrame {
	private MyPanel_ch12_4 panel = new MyPanel_ch12_4();
	private ImageIcon appleIcon = new ImageIcon("images/apple.jpg");
	private Image appleImage = appleIcon.getImage();
	private int x = 50;
	private int y = 50;
	private int width = appleImage.getWidth(this);
	private int height = appleImage.getHeight(this);

	public ch12_4() {
		setTitle("�̹��� ���̺� �巡�� ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(panel);
		setSize(500, 500);
		setVisible(true);
	}

	class MyPanel_ch12_4 extends JPanel {
		boolean okayToMove = false;

		public MyPanel_ch12_4() {
			setFocusable(true);
			requestFocus();

			addMouseListener(new MouseAdapter() {
				public void mousePressed(MouseEvent e) { //���콺�� �������� ��
					Point startP = e.getPoint();  //���� ���콺�� ��ġ
					if (startP.getX() >= x && startP.getX() <= x + width)
						if (startP.getY() >= y && startP.getY() <= y + height)
							okayToMove = true;
				//���콺�� �̹��� ���� �ȿ� �ִ��� Ȯ���ϰ� �̵� �����ϴٴ� ���� ǥ��
				}

				public void mouseReleased(MouseEvent e) {  //������ ��ư�� ���� ��
					if (okayToMove == true) {  //�̵� ������ ���¿��ٸ�
						Point endP = e.getPoint();  //���� ���콺 ��ġ
						x = (int) endP.getX() - width / 2;
						y = (int) endP.getY() - height / 2;  //�̵��� ��ġ ����
						okayToMove = false;
						repaint();  //����� ��ġ�� ���
					}
				}
			});
		}

		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.drawImage(appleImage, x, y, width, height, this);
		}
	}

	public static void main(String[] args) {
		new ch12_4();
	}

}
