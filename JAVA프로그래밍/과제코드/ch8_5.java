import java.awt.*;
import javax.swing.*;

class FaceDrawingComponent extends JComponent{
	public void paintComponent(Graphics g) {
		g.drawOval(20, 30, 200, 200);
		g.setColor(new Color(255,220,130));
		g.fillOval(20, 30, 200, 200);
		
		g.setColor(Color.BLACK);
		g.fillOval(90, 90, 10, 10);
		g.fillOval(150, 90, 10, 10);
		
		g.drawOval(110, 120, 30, 30);
		g.setColor(new Color(230,20,80));
		g.fillOval(110, 120, 30, 30);
		
		g.setColor(Color.BLACK);
		g.drawArc(75, 130, 100, 80, 180, 180);
		g.drawLine(75, 170, 175, 170);
		g.setColor(new Color(0,120,60));
		g.fillArc(75, 130, 100, 80, 180, 180);
	}
}

public class ch8_5 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(300,300);
		frame.setTitle("Face");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		FaceDrawingComponent component = new FaceDrawingComponent();
		frame.add(component);
		frame.setVisible(true);
	}
}
