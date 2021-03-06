abstract class Figure{
	abstract void area();
	abstract void girth();
	abstract void draw();
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
	public void draw() {
		for(int i=0;i<width;i++)System.out.print("*"); System.out.println();
		for(int i=0;i<heigth-2;i++) {
			System.out.print("*");
			for(int j=0;j<width-2;j++) System.out.print(" ");
			System.out.print("*");
			System.out.println();
		}
		for(int i=0;i<width;i++)System.out.print("*"); System.out.println();
		System.out.println();
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
	public void draw() {
		System.out.println("Circle draw");
		  for(int x=-2*radius; x<=2*radius; x+=2) {

			    for(int y=-radius; y<=radius; y++) {

			      if((x*x + y*y) >= radius*radius-radius/1.3 && (x*x + y*y) <= radius*radius+radius/1.3)  

			    	  System.out.print("*");

			      else

			    	  System.out.print(" ");

			    }

			    System.out.println();

			  } 
	}
}
public class prob3 {

	public static void main(String[] args) {
		Rect r = new Rect(10,5);
		Circle c = new Circle(5);
		
		r.area();  r.girth();   r.draw();
		c.area();  c.girth();   c.draw();
	}
}
