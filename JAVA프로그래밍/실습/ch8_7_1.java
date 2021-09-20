import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;

import javax.swing.JComponent;
import javax.swing.JFrame;

interface IDrawStar1 {
	void setColor(Color c);
	void moveStar(int x, int y);
	void draw(Graphics g);
}

class Star1 implements IDrawStar1 {
	Color color;
	int startx, starty;
	public void setColor(Color c) {
		color = c;
	}
	public void moveStar(int x, int y) {
		startx = x;
		starty = y;
	}
	public void draw(Graphics g) {
		Polygon p = new Polygon();
		p.addPoint(startx, starty);
		p.addPoint(startx+30, starty);
		p.addPoint(startx+40, starty-30);
		p.addPoint(startx+50, starty);
		p.addPoint(startx+80, starty);
		p.addPoint(startx+60, starty+20);
		p.addPoint(startx+65, starty+50);
		p.addPoint(startx+40, starty+30);
		p.addPoint(startx+15, starty+50);
		p.addPoint(startx+20, starty+20);
		g.setColor(color);
		g.fillPolygon(p);
		g.setColor(Color.BLACK);
		g.drawPolygon(p);
	}
}
public class ch8_7_1 extends JComponent {
	public void paintComponent(Graphics g) {
		Star1 star1 = new Star1();
		Star1 star2 = new Star1();
		Star1 star3 = new Star1();
		star1.setColor(new Color(0.7F, 1F, 0.7F));
		star2.setColor(new Color(1F, 0.7F, 0.7F));
		star3.setColor(new Color(0.7F, 0.7F, 1F));
		star1.moveStar(70, 70);
		star2.moveStar(130, 70);
		star3.moveStar(100, 100);
		star1.draw(g);
		star2.draw(g);
		star3.draw(g);
	}
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(300, 300);
		frame.setTitle("ExerciseCh08_07");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		ch8_7_1 component = new ch8_7_1();
		frame.add(component);
		frame.setVisible(true);

	}

}