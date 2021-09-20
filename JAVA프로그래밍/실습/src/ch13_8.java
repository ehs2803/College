import java.awt.*;
//import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class ch13_8 extends JFrame{
	private Panel_ch13_8 panel = new Panel_ch13_8();
	private Thread snowThread;
	public ch13_8() {
		super("´« ³»¸®´Â »þ°¥ÀÇ ¸¶À»");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(panel);
		setSize(400,400);
		setVisible(true);
		
		snowThread = new Thread(panel);
		snowThread.start();
	}
	
	class Panel_ch13_8 extends JPanel implements Runnable{
		private Image img;
		public Vector<Point> snowVector = new Vector<Point>();
		public Panel_ch13_8() {
			setLayout(null);

			ImageIcon icon = new ImageIcon("images/bg.jpg");
			img = icon.getImage();
			
			for(int i=0;i<50;i++) {
				int x = (int)(Math.random()*400);
				int y = (int)(Math.random()*400);
				Point p = new Point(x,y);
				snowVector.add(p);
			}
		}
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			g.drawImage(img, 0,0,getWidth(), getHeight(), null);
			
			g.setColor(Color.WHITE);
			for(int i=0;i<snowVector.size();i++) {
				Point p = snowVector.get(i);
				g.fillOval(p.x,p.y,10,10);
			}
		}
		public void changeSnowPosition() {
		    for(int i=0;i<snowVector.size();i++) {
			    Point p = snowVector.get(i);
			    int y = p.y;
			    if(y+5>400) y=0;
			    else y+=5;
			    Point newp = new Point(p.x,y);
			    snowVector.set(i, newp);
		    }
	    }	
		public void run() {
			while(true) {
				try {
					Thread.sleep(300);
				}
				catch(InterruptedException e) { return;}
				changeSnowPosition();
				repaint();
			}
		}
	}
	/*
	class SnowThread extends Thread{
		public void run() {
			while(true) {
				try {
					sleep(300);
				}
				catch(InterruptedException e) { return;}
				changeSnowPosition();
				repaint();
			}
		}
	}
	*/
	public static void main(String[] args) {
		new ch13_8();
	}
}
