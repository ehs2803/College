import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch13_6 extends JFrame{
	public ch13_6() {
		setTitle("버블 게임");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(new BubbleGamePanel());
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch13_6();
	}
}

class BubbleGamePanel extends JPanel{
	public BubbleGamePanel() {
		setLayout(null);
		addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				BubbleThread bubblethread = new BubbleThread(e.getX(), e.getY());
				bubblethread.start();
			}
		});
	}
	
	class BubbleThread extends Thread{
		JLabel bubble;
		public BubbleThread(int bubblex, int bubbley) {
			ImageIcon img = new ImageIcon("images/chicken.jpg");
			bubble = new JLabel(img);
			bubble.setSize(50,50);
			bubble.setLocation(bubblex,bubbley);
			add(bubble);
			repaint();
		}
		
		public void run() {
			while(true) {
				int x=bubble.getX();
				int y=bubble.getY()-5;
				if(y<0) {
					remove(bubble);
					repaint();
					return;
				}
				bubble.setLocation(x,y);
				repaint();
				try {
					sleep(200);
				}
				catch(InterruptedException e) {}
			}
		}
	}
}