/*
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class WhiteboardComponent extends JComponent{
	int x,y,w,h;
	WhiteboardComponent(){
		x=0;
		y=0;
		w=0;
		h=0;
		
		addMouseListener(new MouseEventHdl());
		addMouseMotionListener(new MouseMotionHdl());
	}
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(Color.BLACK);
		g.drawString("마우스로 사각형을 그리시오.", 20, 50);
		g.setColor(Color.RED);
		g.drawRect(x, y, w, h);
		g.drawLine(x, y, x+w, y+h);
		g.drawLine(x+w, y, x, y+h);
	}
	public void setStartPoint(int x, int y) {
		this.x=x;
		this.y=y;
	}
	public void setEndPoint(int x, int y) {
		w=Math.abs(this.x-x);
		h=Math.abs(this.y-y);
	}
	class MouseEventHdl extends MouseAdapter{
		public void muosePressed(MouseEvent e) {
			x=e.getX(); y=e.getY();
			setStartPoint((int)e.getX(),(int)e.getY());
		}
		public void mouseReleased(MouseEvent e) {
			setEndPoint((int)e.getX(),(int)e.getY());
			repaint();
		}
	}
	class MouseMotionHdl extends MouseMotionAdapter{
		public void mouseDragged(MouseEvent e) {
			setEndPoint((int)e.getX(), (int)e.getY());
			repaint();
		}
	}
}

public class ch12_8 {
	public static void main(String[] args) {
		JFrame f = new JFrame("MouseEventTest");
		f.setSize(320,240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		f.add(new WhiteboardComponent());
		
		f.setVisible(true);
	}
}
*/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class WhiteboardComponent extends JComponent {
	int x, y, w, h;

	WhiteboardComponent() { // 생성자
		x = 0;
		y = 0;
		w = 0;
		h = 0;

		addMouseListener(new MouseEventHdl()); // 처리기 등록
		addMouseMotionListener(new MouseMotionHdl()); // 처리기 등록
	}

	public void paintComponent(Graphics g) {
		g.setColor(Color.BLACK);
		g.drawString("마우스로 사각형을 그리세요.", 20, 50);
		g.setColor(Color.RED);
		g.drawRect(x, y, w, h);
		// 추가된 코드 : X 그리기
		g.drawLine(x, y, x+w, y+h);
		g.drawLine(x+w, y, x, y+h);
	}

	public void setStartPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void setEndPoint(int x, int y) {
		w = Math.abs(this.x - x);
		h = Math.abs(this.y - y);
	}

	class MouseEventHdl extends MouseAdapter {
		public void mousePressed(MouseEvent e) { // 이벤트 처리기
			setStartPoint(e.getX(), e.getY());
		}

		public void mouseReleased(MouseEvent e) { // 이벤트 처리기
			setEndPoint(e.getX(), e.getY());
			repaint();
		}
	}

	class MouseMotionHdl extends MouseMotionAdapter {
		public void mouseDragged(MouseEvent e) { // 이벤트 처리기
			setEndPoint(e.getX(), e.getY());
			repaint();
		}
	}
}

public class ch12_8 {
	public static void main(String[] args) {
		JFrame f = new JFrame("MouseEventTest");
		f.setSize(320, 240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		f.add(new WhiteboardComponent());

		f.setVisible(true);
	}
}

