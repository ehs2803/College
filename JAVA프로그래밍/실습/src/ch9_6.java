import java.awt.*;
import javax.swing.*;

public class ch9_6 extends JFrame{
	public ch9_6() {
		super("Random Labels");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(null);
		
		for(int i=1;i<=20;i++) {
			JLabel jl= new JLabel(Integer.toString(i));
			jl.setBackground(Color.BLUE);
			jl.setSize(10,10);
			int x = (int)(Math.random()*200)+50;
			int y = (int)(Math.random()*200)+50;
			jl.setLocation(x, y);
			jl.setOpaque(true);
			c.add(jl);
		}
		
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch9_6();
	}
}
//20210505