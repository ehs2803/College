import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class MyPanel_ch13_2 extends JPanel {
	private int x;
	private int y;
	private boolean flag = false;

	public MyPanel_ch13_2() {
		this.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				flag = true;
				repaint();
			}
		});
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		if (flag == true) {
			g.setColor(Color.MAGENTA);
			x = (int) (Math.random() * this.getWidth() - 50);
			y = (int) (Math.random() * this.getHeight() - 50);
			g.drawOval(x, y, 50, 50);
		}
	}
}

class MyThread_ch13_2 extends Thread {
	private MyPanel_ch13_2 panel;

	public MyThread_ch13_2(MyPanel_ch13_2 panel) {
		this.panel = panel;
	}

	public void run() {
		while (true) {
			panel.repaint();
			try {
				sleep(400);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
}

public class ch13_2 extends JFrame {
	private MyPanel_ch13_2 panel = new MyPanel_ch13_2();

	public ch13_2() {
		setTitle("원을 0.5초 간격으로 생성하는 프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(panel);

		setSize(300, 300);
		setVisible(true);

		panel.setFocusable(true);
		panel.requestFocus();

		MyThread_ch13_2 th = new MyThread_ch13_2(panel);
		th.start();
	}

	public static void main(String[] args) {
		new ch13_2();
	}

}

