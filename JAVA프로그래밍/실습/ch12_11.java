/*
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ch12_11 extends JFrame {
	JTextField tf1 = new JTextField(3);
	JTextField tf2 = new JTextField(3);
	JTextField tf3 = new JTextField(3);
	JButton btn = new JButton("set");
	int h=12;
	ClockDrawingComponent Clock = new ClockDrawingComponent();
	ch12_11(){
		setSize(250,250);
		setTitle("Clock");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		add(Clock, BorderLayout.CENTER);
		
		add(new InputPanel(), BorderLayout.SOUTH);
		
		setVisible(true);
	}
	
	private void drawChart() {
		int sum=0;
		for(int i=0; i<data.length; i++) {
			data[i] = Integer.parseInt(tf[i].getText());
			sum+=data[i];			
		}

		if(sum == 0) return;

		for(int i=0; i<data.length; i++) 
			arcAngle[i]=(int)Math.round((double)data[i]/(double)sum*360);
		
		chartPanel.repaint();
	}
	
	class ClockDrawingComponent extends JPanel{
		int x[] = {0,0,135,0,0,95,0,0,55,0,0, 95};
		int y[] = {0,0,95,0,0,135,0,0,95,0,0,55};
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			
			g.setColor(Color.RED);
			g.fillOval(20, 20,150, 150);
			
			g.setColor(Color.YELLOW);
			g.fillOval(40, 40, 110, 110);
			
			g.setColor(Color.BLACK);
			g.fillOval(92, 92, 6, 6);
			
			
			g.setColor(Color.BLUE);
			g.drawLine(95, 95, x[h-1], y[h-1]);
			//95,55   135,95  95,135  55,95
			
			g.drawLine(95, 95, 140, 95);
			
			g.setColor(Color.RED);
			g.drawLine(105, 85, 60, 120);
		}
	}
	private class InputPanel extends JPanel {
		JLabel jl1 = new JLabel(":");
		JLabel jl2 = new JLabel(":");
		public InputPanel() {
			add(tf1); add(jl1); add(tf2); add(jl2); add(tf3); add(btn);
			btn.addActionListener(new MyActionListener());
		}
		//여기에 MyActionListener 구현하면 이벤트 처리 않됨.
		
	}
	private class MyActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) { // <Enter> 키 처리
			h = Integer.parseInt(tf1.getText());
			repaint();
		}
	}
	public static void main(String[] args) {
		new ch12_11();
	}
}
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Clock1 extends JComponent {
	double hour, minute, second;

	public void paintComponent(Graphics gp) {
		double posHour, posMinute, posSecond, radius;
		int pointX;
		int pointY;
		int endX, endY;
		
		gp.setColor(Color.RED);
		gp.fillOval(20, 20, 150, 150);

		gp.setColor(Color.YELLOW);
		gp.fillOval(40, 40, 110, 110);

		gp.setColor(Color.BLACK);
		gp.fillOval(92, 92, 6, 6);

		for(int i=1;i<=12;i++) {
			double temp1 = Math.PI * i*5 / 30.0;
			double temp2 = 95 * 0.7;
			int x = (int) Math.round(90 + temp2 * Math.sin(temp1));
			int y = (int) Math.round(100 - temp2 * Math.cos(temp1));
			gp.setColor(Color.BLACK);
			gp.drawString(Integer.toString(i), x, y);
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
			gp.setColor(Color.BLACK);
			gp.drawLine(x1,y1,x2,y2);
		}
		
		posHour = Math.PI * (hour / 6.0 + minute / 360.0);
		radius = 95 * 0.4;
		pointX = (int) Math.round(95 + radius *  Math.sin(posHour));
		pointY = (int) Math.round(95 - radius *  Math.cos(posHour));
		gp.setColor(Color.BLUE);
		gp.drawLine(95, 95, pointX, pointY);

		posMinute = Math.PI * (minute / 30.0);//+ second / 1800.0
		radius = 95 * 0.5;	
		pointX = (int) Math.round(95 + radius * Math.sin(posMinute));
		pointY = (int) Math.round(95 - radius * Math.cos(posMinute));
		gp.drawLine(95, 95, pointX, pointY);
		
		posSecond = Math.PI * second / 30.0;
		radius = 95 * 0.6;
		endX = (int) Math.round(95 + radius * Math.sin(posSecond));
		endY = (int) Math.round(95 - radius * Math.cos(posSecond));
		gp.setColor(Color.RED);
		gp.drawLine(95, 95, endX, endY);
	}
}

public class ch12_11 implements ActionListener {
	Clock1 c = new Clock1();

	JFrame f = new JFrame("Clock");
	JButton b = new JButton("Set");
	JTextField hour = new JTextField(2); 
	JTextField minute = new JTextField(2); 
	JTextField second = new JTextField(2); 
	JPanel p = new JPanel();

	public void start() {
		p.add(hour);
		p.add(new JLabel(":"));
		p.add(minute);
		p.add(new JLabel(":"));
		p.add(second);
		p.add(b);
		b.addActionListener(this);

		f.setSize(200, 260);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		f.add(BorderLayout.CENTER, c);
		f.add(BorderLayout.SOUTH, p);

		f.setVisible(true);
	}

	public static void main(String[] args) {
		ch12_11 ex = new ch12_11();
		ex.start();
	}

	public void actionPerformed(ActionEvent e) {
		c.hour = Double.parseDouble(hour.getText());
		c.minute = Double.parseDouble(minute.getText());
		c.second = Double.parseDouble(second.getText());

		c.repaint();
	}
}
