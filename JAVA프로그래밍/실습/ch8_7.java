import java.awt.*;
import javax.swing.*;

interface IDrawStar{
	void setColor(Color c);
	void moveStar(int x, int y);
	void draw(Graphics g);
}

class Star implements IDrawStar{
	Color c;
	int x, y;
	public void setColor(Color c) {
		this.c=c;
	}
	public void moveStar(int x, int y) {
		this.x=x;
		this.y=y;
	}
	public void draw(Graphics g) {
		g.setColor(c);
		int x2[] = { 210+x,175+x,60+x,150+x,110+x,210+x,310+x,270+x,360+x,245+x,210+x };
		int y2[] = { 60+y,160+y,160+y,225+y,340+y,270+y,340+y,225+y,160+y,160+y,60+y };
		g.fillPolygon( x2, y2, 10 );  
	}
}

class StarComponent extends JComponent{
	Star s1,s2,s3;
	public StarComponent(Star s1, Star s2, Star s3) {
		this.s1=s1;
		this.s2=s2;
		this.s3=s3;
	}
	public void paintComponent(Graphics g) {
		s1.draw(g);
		s2.draw(g);
		s3.draw(g);
	}
}

public class ch8_7 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(500,500);
		frame.setTitle("star");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Star s1 = new Star(); s1.setColor(Color.RED); 
		Star s2 = new Star(); s2.setColor(Color.GREEN); s2.moveStar(100, 0);
		Star s3 = new Star(); s3.setColor(Color.BLUE); s3.moveStar(50, 100);
		
		StarComponent component = new StarComponent(s1,s2,s3);
		
		frame.add(component);
		frame.setVisible(true);
	}
}
