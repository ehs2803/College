import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class WhiteboardComponent extends JComponent implements ActionListener {
	JRadioButton [] rb = new JRadioButton[4];
	Color color = Color.black;
	int x=0, y=0;

	WhiteboardComponent(JPanel p) { 
		setBackground(Color.white);

		rb[0] = new JRadioButton("??????", true);
		rb[0].setBackground(Color.black);
		rb[0].setForeground(Color.white);
		rb[0].addActionListener(this);

		rb[1] = new JRadioButton("??????", false);
		rb[1].setBackground(Color.red);
		rb[1].addActionListener(this);

		rb[2] = new JRadioButton("??????", false);
		rb[2].setBackground(Color.magenta);
		rb[2].addActionListener(this);

		rb[3] = new JRadioButton("??  ??", false);
		rb[3].setBackground(Color.green);
		rb[3].addActionListener(this);
		
		ButtonGroup group = new ButtonGroup();
		group.add(rb[0]);
		group.add(rb[1]);
		group.add(rb[2]);
		group.add(rb[3]);

		p.add(rb[0]);
		p.add(rb[1]);
		p.add(rb[2]);
		p.add(rb[3]);
		
		addMouseListener(new MouseEventHdl()); 
		addMouseMotionListener(new MouseMotionHdl()); 
	}

	public void actionPerformed(ActionEvent e) {
		JRadioButton rb = (JRadioButton) e.getSource();

		if (e.getActionCommand().equals("??????"))
			color = Color.black;
		else if (e.getActionCommand().equals("??????"))
			color = Color.red;
		else if (e.getActionCommand().equals("??????"))
			color = Color.magenta;
		else if (e.getActionCommand().equals("??  ??"))
			color = Color.green;
	}
	
	public class MouseMotionHdl extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e) {
			Graphics g = getGraphics();
			g.setColor(color);
			g.drawLine(x, y, e.getX(), e.getY());
			x = e.getX();
			y = e.getY();
		}
	}

	public class MouseEventHdl extends MouseAdapter {
		public void mousePressed(MouseEvent e) {
			x = e.getX();
			y = e.getY();
		}
	}
}

public class prob1 extends JFrame {
	public prob1() {
		super("WhiteBoard");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBackground(Color.white);
		
		JPanel p = new JPanel();
		WhiteboardComponent wb = new WhiteboardComponent(p);
		add(BorderLayout.NORTH, p);
		add(BorderLayout.CENTER, wb);
		
		setSize(400, 300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new prob1();
	}
}
