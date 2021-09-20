import java.util.Scanner;
import java.awt.*;
import javax.swing.*;

abstract class Figure{
	abstract void area();
	abstract void girth();
	abstract void draw(Graphics g);
}

class Rect extends Figure{
	private int width, heigth;
	public Rect(int w, int h) {
		width=w;
		heigth=h;
	}
	public void area() {
		System.out.println("Rect area=" + (width*heigth));
	}
	public void girth() {
		System.out.println("Rect Girth= " +(2*width+2*heigth));
	}
	public void draw(Graphics g) {
		g.drawRect(10, 10, width, heigth);
	}
}

class Circle extends Figure{
	private int radius;
	public Circle(int r) {radius=r;}
	public void area() {
		System.out.println("Circle Rect= "+(3.14*radius*radius));
	}
	public void girth() {
		System.out.println("Circle Girth= "+(2*3.14*radius));
	}
	public void draw(Graphics g) {
		g.drawOval(200, 10, 2*radius, 2*radius);
	}
}

class UserDefinedComponent extends JComponent{
	public void paintComponent(Graphics g) {
		Scanner sc = new Scanner(System.in);
		System.out.print("사격형의 너비와 높이를 입력하시요: ");
		int w = sc.nextInt();
		int h = sc.nextInt();
		Rect rect = new Rect(w, h);
		
		System.out.print("원의 반지름을 입력하시오: ");
		int r = sc.nextInt();
		Circle circle = new Circle(r);
		
		rect.area();
		rect.girth();
		rect.draw(g);
		
		circle.area();
		circle.girth();
		circle.draw(g);
		
		sc.close();
	}
}

public class ch6_10{
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		
		frame.setTitle("draw rectangle and circle");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(400,200);
		
		UserDefinedComponent component = new UserDefinedComponent();
		frame.add(component);
		
		frame.setVisible(true);
	}
}
