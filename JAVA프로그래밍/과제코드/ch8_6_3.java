import java.awt.*;
import javax.swing.*;

class OlympicflagDrawingComponent extends JComponent{
	public void paintComponent(Graphics g) {
		g.setColor(Color.BLUE);
		g.drawOval(50, 20, 60, 60);
		g.drawOval(51, 20, 60, 60);g.drawOval(52, 20, 60, 60);g.drawOval(53, 20, 60, 60);
		g.drawOval(50, 21, 60, 60);g.drawOval(50, 22, 60, 60);g.drawOval(50, 23, 60, 60);
		
		
		
		g.setColor(Color.BLACK);
		g.drawOval(110, 20, 60, 60);
		g.setColor(Color.RED);
		g.drawOval(170, 20, 60, 60);
		g.setColor(Color.YELLOW);
		g.drawOval(75, 45, 60, 60);
		g.setColor(Color.GREEN);
		g.drawOval(145, 45, 60, 60);
	}
}

public class ch8_6_3 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(300,300);
		frame.setTitle("Olympicflag");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		OlympicflagDrawingComponent component = new OlympicflagDrawingComponent();
		frame.add(component);
		frame.setVisible(true);
	}
}
