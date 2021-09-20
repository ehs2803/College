import java.awt.*;
import javax.swing.*;

class HouseDrawingComponent extends JComponent{
	public void paintComponent(Graphics g) {
		//���ر׸���
		int[] xPnts = {100,50,150,100};
		int[] yPnts = {30,180,180,30};
		int nPnts = xPnts.length;
		g.fillPolygon(xPnts, yPnts, nPnts);
		
		//���� ���� ��� ����� �׸���
		g.setColor(Color.WHITE);
		g.drawArc(90, 50, 20, 40, 210, 120);
		g.drawArc(75, 87, 20, 40, 210, 120);
		g.drawArc(105, 87, 20, 40, 210, 120);
		g.drawArc(60, 125, 20, 40, 210, 120);
		g.drawArc(90, 125, 20, 40, 210, 120);
		g.drawArc(120, 125, 20, 40, 210, 120);
		
		//��ä�� �׸���
		g.setColor(Color.BLACK);
		g.drawRect(60,180,80,100);
		
		//�ݿ� ����� â���� �׸���.
		g.setColor(Color.YELLOW);
		g.fillArc(80,195,40,85,0,180);
		
		//����� â�� ������ 2���� ������ ������ �׸���.
		g.setColor(Color.BLACK);
		g.drawArc(80, 195, 40, 85, 0, 180);
		g.drawArc(79,195,42,86,0,180);
		g.drawLine(79, 238, 120, 238);
		g.drawLine(79, 239, 120, 239);
		
		//���� �׸���.
		g.setColor(Color.GRAY);
		g.fillRect(85, 250, 30, 30);
		g.setColor(Color.BLACK);
		g.drawRect(85, 250, 30, 30);
		g.drawLine(100, 250, 100, 280);
		g.fillOval(96, 260, 8, 8);
	}
}	
	
public class ch8_4 {
	public static void main(String[] args) {	
		JFrame frame = new JFrame();
		frame.setSize(250,350);
		frame.setTitle("House");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		HouseDrawingComponent component = new HouseDrawingComponent();
		frame.add(component);
		frame.setVisible(true);	
	}
}
