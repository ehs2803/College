import java.awt.*;
import javax.swing.*;

class MyThread_ch13_4 extends Thread {
	private JFrame frame;

	public MyThread_ch13_4(JFrame frame) {
		this.frame = frame;
	}

	public void run() {
		while (true) {
			frame.setLocation(110, 100);
			try {
				sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			frame.setLocation(105, 105);
			try {
				sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			frame.setLocation(100, 110);
			try {
				sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			frame.setLocation(105, 105);
			try {
				sleep(10);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
}

public class ch13_4 extends JFrame {

	public ch13_4() {
		setTitle("진동하는 프레임 만들기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		setSize(400, 300);
		setVisible(true);

		MyThread_ch13_4 th = new MyThread_ch13_4(this);
		th.start();
	}

	public static void main(String[] args) {
		new ch13_4();
	}

}
/*
import java.awt.*;
import javax.swing.*;

class MyLabel extends JLabel implements Runnable {

	public MyLabel(String text) {
		super(text);
		setFont(new Font("굴림", Font.PLAIN, 30));
		setSize(200, 80);

		Thread th = new Thread(this);
		th.start();
	}

	public void run() {
		while (true) {
			setLocation(110, 100);
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			setLocation(105, 105);
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			setLocation(100, 110);
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			setLocation(105, 105);
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
}

public class Exercise extends JFrame {

	public Exercise() {
		setTitle("진동하는 레이블 만들기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);
		c.add(new MyLabel("진동 레이블"));

		setSize(400, 400);
		setVisible(true);
	}

	public static void main(String[] args) {
		new Exercise();
	}

}
*/