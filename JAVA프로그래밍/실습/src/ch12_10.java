import javax.swing.*;
import java.awt.*;

public class ch12_10 extends JFrame {
	private MyPanel_ch12_10 panel = new MyPanel_ch12_10();

	public ch12_10() {
		setTitle("그래픽 이미지 연습");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(panel);
		setSize(350, 350);
		setVisible(true);
	}

	class MyPanel_ch12_10 extends JPanel {
		ImageIcon icon = new ImageIcon("images/backiee-88210.jpg");
		Image image = icon.getImage();
		int iw = (icon.getIconWidth() - 10) / 2;
		int ih = (icon.getIconHeight() - 10) / 2;

		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			int pw = (getWidth() - 10) / 2;
			int ph = (getHeight() - 10) / 2;
			g.drawImage(image, 0, 0, pw, ph, 0, 0, iw, ih, this);
			g.drawImage(image, pw + 10, 0, pw * 2 + 10, ph, iw + 10, 0, iw * 2 + 10, ih, this);
			g.drawImage(image, 0, ph + 10, pw, ph * 2 + 10, 0, ih + 10, iw, ih * 2 + 10, this);
			g.drawImage(image, pw + 10, ph + 10, pw * 2 + 10, ph * 2 + 10, iw + 10, ih + 10, iw * 2 + 10, ih * 2 + 10,
					this);
		}
	}

	public static void main(String[] args) {
		new ch12_10();
	}

}