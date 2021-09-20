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
		setTitle("이미지 레이블 드래깅 연습");
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
				public void mousePressed(MouseEvent e) { //마우스가 눌러졌을 때
					Point startP = e.getPoint();  //현재 마우스의 위치
					if (startP.getX() >= x && startP.getX() <= x + width)
						if (startP.getY() >= y && startP.getY() <= y + height)
							okayToMove = true;
				//마우스가 이미지 영역 안에 있는지 확인하고 이동 가능하다는 것을 표현
				}

				public void mouseReleased(MouseEvent e) {  //눌렀던 버튼을 뗐을 때
					if (okayToMove == true) {  //이동 가능한 상태였다면
						Point endP = e.getPoint();  //현재 마우스 위치
						x = (int) endP.getX() - width / 2;
						y = (int) endP.getY() - height / 2;  //이동할 위치 설정
						okayToMove = false;
						repaint();  //변경된 위치에 출력
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
