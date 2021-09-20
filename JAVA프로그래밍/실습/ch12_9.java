/*
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


class MyPaint extends JComponent{
	Color c;
	int x,y;
	MyPaint(){
		this.setLayout(new FlowLayout());
		ButtonGroup grp = new ButtonGroup();
		JRadioButton[] rb = new JRadioButton[4];
		rb[0]=new JRadioButton("������"); rb[0].setBackground(Color.BLACK);
		rb[1]=new JRadioButton("������"); rb[1].setBackground(Color.RED);
		rb[2]=new JRadioButton("��ȫ��"); rb[2].setBackground(Color.MAGENTA);
		rb[3]=new JRadioButton("���"); rb[3].setBackground(Color.GREEN);
		
		addMouseMotionListener(new MouseMotion());
		
		for(JRadioButton c:rb) {
			grp.add(c);
			add(c);
			//c.setActionCommand(c.getText());
			c.addActionListener(new RadioColor());
		}	
		
	}
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.fillOval(x, y, 5, 5);
	}

	class MouseEvent extends MouseAdapter{
		public void muosePressed(MouseEvent e) {
			
		}
		public void mouseReleased(MouseEvent e) {
			
			repaint();
		}
	}
	class MouseMotion extends MouseMotionAdapter{
		public void mouseDragged(MouseEvent e) {
			x=5;
			y=5;
			repaint();
		}
	}
	
	class RadioColor implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			JRadioButton rb = (JRadioButton)e.getSource();
			
			if(e.getActionCommand().equals("������")) c=Color.BLACK;
			else if(e.getActionCommand().equals("������")) c=Color.RED;
			else if(e.getActionCommand().equals("��ȫ��")) c=Color.MAGENTA; 
			else if(e.getActionCommand().equals("���")) c=Color.GREEN;
		}
	}
}
public class ch12_9 {
	public static void main(String[] args) {
		JFrame f = new JFrame("WhiteBoard");
		f.setSize(320,240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.add(new MyPaint());

		f.setVisible(true);
	}
}
*/
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

class WhiteboardComponent1 extends JComponent implements ActionListener {
	JRadioButton rb1, rb2, rb3, rb4;
	Color curCol = Color.black;
	int x=0, y=0;

	WhiteboardComponent1(JPanel p) { // ������
		setBackground(Color.white);

		
		rb1 = new JRadioButton("������", true);
		rb1.setBackground(Color.black);
		rb1.setForeground(Color.white);
		rb1.addActionListener(this);

		rb2 = new JRadioButton("������", false);
		rb2.setBackground(Color.red);
		rb2.addActionListener(this);

		rb3 = new JRadioButton("�����", false);
		rb3.setBackground(Color.magenta);
		rb3.addActionListener(this);

		rb4 = new JRadioButton("��  ��", false);
		rb4.setBackground(Color.green);
		rb4.addActionListener(this);
		ButtonGroup grp = new ButtonGroup();
		grp.add(rb1);
		grp.add(rb2);
		grp.add(rb3);
		grp.add(rb4);

		p.add(rb1);
		p.add(rb2);
		p.add(rb3);
		p.add(rb4);
		
		addMouseListener(new MouseEventHdl()); // ó���� ���
		addMouseMotionListener(new MouseMotionHdl()); // ó���� ���
	}

	public void actionPerformed(ActionEvent e) {
		JRadioButton rb = (JRadioButton) e.getSource();

		if (e.getActionCommand().equals("������"))
			curCol = Color.black;
		else if (e.getActionCommand().equals("������"))
			curCol = Color.red;
		else if (e.getActionCommand().equals("�����"))
			curCol = Color.magenta;
		else if (e.getActionCommand().equals("��  ��"))
			curCol = Color.green;
	}
	
	public class MouseMotionHdl extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e) {
			Graphics g = getGraphics();
			g.setColor(curCol);
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

public class ch12_9 {
	public static void main(String[] args) {
		JFrame f = new JFrame("Whiteboard");
		JPanel p = new JPanel();
		f.setSize(320, 240);
		f.setBackground(Color.white);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		WhiteboardComponent1 wb = new WhiteboardComponent1(p);
		f.add(BorderLayout.NORTH, p);
		f.add(BorderLayout.CENTER, wb);

		f.setVisible(true);
	}
}
