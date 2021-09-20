import java.awt.*;
import javax.swing.*;

public class ch9_5 extends JFrame {
	public ch9_5() {
		setTitle("4*4 Color Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new GridLayout(4,4));
		float[] f = new float[] { 0, 0, 0 };
		
		for(int i=0;i<=15;i++) {
			JLabel jl = new JLabel(Integer.toString(i));
			jl.setOpaque(true);
			for (int j = 0; j < 3; j++) {
				f[j] = (float) (Math.random());
			}
			Color bgColor = Color.getHSBColor(f[0], f[1], f[2]);
			c.add(jl).setBackground(bgColor);
		}
		setSize(400,400);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch9_5();
	}
}
//20210505