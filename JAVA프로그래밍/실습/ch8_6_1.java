import java.awt.*;
import javax.swing.*;

class ItalyComponent extends JComponent{
	public void paintComponent(Graphics g) {
		g.setColor(Color.GREEN);
		g.fillRect(100, 100, 30, 60);
		
		g.setColor(Color.WHITE);
		g.fillRect(130, 100, 30, 60);
		
		g.setColor(Color.BLACK);
		g.drawLine(130, 100, 160, 100);
		g.drawLine(130, 160, 160, 160);
		
		g.setColor(Color.RED);
		g.fillRect(160, 100, 30, 60);
		
		
		g.setColor(Color.BLACK);
		g.fillOval(150, 200, 100, 100);
		
		g.setColor(Color.WHITE);
		g.fillOval(160, 210, 80, 80);
		
		g.setColor(Color.BLACK);
		g.fillOval(170, 220, 60, 60);
		
		g.setColor(Color.WHITE);
		g.fillOval(180, 230, 40, 40);
		
		g.setColor(Color.BLACK);
		g.fillOval(190, 240, 20, 20);
		
	}
}

public class ch8_6_1 {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(500,500);
		frame.setTitle("이탈리아 국기");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		ItalyComponent component = new ItalyComponent();
		frame.add(component);
		frame.setVisible(true);
	}
}
