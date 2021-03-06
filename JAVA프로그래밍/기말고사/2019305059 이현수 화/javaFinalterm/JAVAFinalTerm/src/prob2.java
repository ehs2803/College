import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Calendar;


public class prob2 extends JFrame {
	Calendar now = Calendar.getInstance();
	Clock clock= new Clock();
	Thread th = new Thread(clock);
	
	public JLabel hourLabel = new JLabel(Integer.toString(now.get(Calendar.HOUR_OF_DAY))); 
	public JLabel minuteLabel = new JLabel(Integer.toString(now.get(Calendar.MINUTE))); 
	public JLabel secondLabel = new JLabel(Integer.toString(now.get(Calendar.SECOND))); 
	JPanel p = new JPanel();
	
	public prob2() {
		super("Clock");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c= getContentPane();
		
		c.add(clock);
		
		p.add(hourLabel);
		p.add(new JLabel(":"));
		p.add(minuteLabel);
		p.add(new JLabel(":"));
		p.add(secondLabel);
		
		add(BorderLayout.CENTER, clock);
		add(BorderLayout.SOUTH, p);
		setSize(200,260);
		setVisible(true);
		
		th.start();
	}
	public static void main(String[] args) {
		new prob2();
	}
	
	class Clock extends JComponent implements Runnable{
		double hour, minute, second;
		public Clock() {
			hour=now.get(Calendar.HOUR_OF_DAY);
			minute=now.get(Calendar.MINUTE);
			second=now.get(Calendar.SECOND);
			
		}
		public void paintComponent(Graphics g) {
			double posHour, posMinute, posSecond, radius;
			int pointX;
			int pointY;
			int endX, endY;
			
			g.setColor(Color.RED);
			g.fillOval(20, 20, 150, 150);

			g.setColor(Color.YELLOW);
			g.fillOval(40, 40, 110, 110);

			g.setColor(Color.BLACK);
			g.fillOval(92, 92, 6, 6);
			
			for(int i=1;i<=12;i++) {
				double temp1 = Math.PI * i*5 / 30.0;
				double temp2 = 95 * 0.7;
				int x = (int) Math.round(90 + temp2 * Math.sin(temp1));
				int y = (int) Math.round(100 - temp2 * Math.cos(temp1));
				g.setColor(Color.BLACK);
				g.drawString(Integer.toString(i), x, y);
			}
			
			for(int i=1;i<=60;i++) {
				double temp1 = Math.PI * i / 30.0;
				double temp2 = 95 * 0.6;
				int x1 = (int) Math.round(95 + temp2 * Math.sin(temp1));
				int y1 = (int) Math.round(95 - temp2 * Math.cos(temp1));
				temp2 = 95 * 0.55;
				if(i%5==0) temp2 = 95 * 0.5;
				int x2 = (int) Math.round(95 + temp2 * Math.sin(temp1));
				int y2 = (int) Math.round(95 - temp2 * Math.cos(temp1));
				g.setColor(Color.BLACK);
				g.drawLine(x1,y1,x2,y2);
			}
			posHour = Math.PI * (hour / 6.0 + minute / 360.0); 
			radius = 95 * 0.4;
			pointX = (int) Math.round(95 + radius * Math.sin(posHour));
			pointY = (int) Math.round(95 - radius * Math.cos(posHour));
			g.setColor(Color.BLUE);
			g.drawLine(95, 95, pointX, pointY);

			posMinute = Math.PI * (minute / 30.0 );
			radius = 95 * 0.5;
			pointX = (int) Math.round(95 + radius * Math.sin(posMinute));
			pointY = (int) Math.round(95 - radius * Math.cos(posMinute));
			g.drawLine(95, 95, pointX, pointY);

			posSecond = Math.PI * second / 30.0;
			radius = 95 * 0.6;
			endX = (int) Math.round(95 + radius * Math.sin(posSecond));
			endY = (int) Math.round(95 - radius * Math.cos(posSecond));
			g.setColor(Color.RED);
			g.drawLine(95, 95, endX, endY);
		}
		public void run() {
			while(true) {
				try {
					Thread.sleep(1000);
					if(second==59) {
						second=0;
						if(minute==59) {
							minute=0;
							if(hour==11) hour=0;
							else hour++;
						}
						else {
							minute++;
						}
					}
					else {
						second++;
					}
					int h = (int)hour;
					int m = (int)minute;
					int s = (int)second;
					hourLabel.setText(Integer.toString(h));
					minuteLabel.setText(Integer.toString(m)); 
					secondLabel.setText(Integer.toString(s)); 
					repaint();
				}
				catch(InterruptedException e) {}
			}
		}
	}
}

