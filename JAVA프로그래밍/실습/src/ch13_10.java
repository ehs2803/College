import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class ch13_10 extends JFrame {
	public ch13_10() {
		super("Make Drawing to Start");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setContentPane(new DrawingPanel());
		
		setSize(400,400);
		setVisible(true);
	}
	
	class DrawingPanel extends JPanel{
		DrawingThread th = new DrawingThread(this);
		Rectangle r = new Rectangle(0,0,0,0);
		
		public DrawingPanel() {
			this.addMouseListener(new MouseHandler());
			th.start();
		}
		
		public void setObj(int x, int y, int w, int h) {
			r.x=x;
			r.y=y;
			r.width=w;
			r.height=h;
		}
		
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			if(r.width==0 || r.height==0) return;
			g.setColor(Color.MAGENTA);
			g.fillOval(r.x, r.y, r.width, r.height);
		}
		
		class MouseHandler extends MouseAdapter{
			public void mouseEntered(MouseEvent e) {
				setTitle("Make Drawing to pause");
				th.wakeup();
			}
			public void mouseExited(MouseEvent e) {
				setTitle("Make Drawing to Pause");
				th.pause();
			}
		}
	}
	
	class DrawingThread extends Thread{
		boolean running = true;
		
		Object obj = new Object();
		DrawingPanel p;
		Random r = new Random(new Date().getTime());
		
		public DrawingThread(DrawingPanel p) {
			this.p=p;
		}
		public void wakeup() {
			running = true;
			synchronized(obj) {
				obj.notify();
			}
		}
		public void pause() {
			running = false;
		}
		public void run() {
			try {
				synchronized(obj) {
					obj.wait();
				}
			}catch(InterruptedException e) {
				return;
			}
			
			while(true) {
				if(p.isValid()) {
					if(!running) {
						try {
							synchronized(obj) {
								obj.wait();
							}
						}catch(InterruptedException e) {
							return;
						}
					}
					int x = r.nextInt(p.getWidth());
					int y = r.nextInt(p.getHeight());
					int w = r.nextInt(100)+1;
					int h = r.nextInt(100)+1;
					
					p.setObj(x, y, w, h);
					
					p.repaint();
				}
				try {
					Thread.sleep(300);
				}catch(InterruptedException e) {
					return;
				}
			}
		}
		
	}
	
	public static void main(String[] args) {
		new ch13_10();
	}
}
