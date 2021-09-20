import java.awt.*;
import javax.swing.*;

public class ch9_8 extends JFrame {
	public ch9_8() {
		super("여러 개의 패널을 가진 프레임");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		c.add(new NorthPanel_ch9_8(), BorderLayout.NORTH);
		c.add(new CenterPanel_ch9_8(), BorderLayout.CENTER);
		c.add(new SouthPanel_ch9_8(), BorderLayout.SOUTH);
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String [] args) {
		new ch9_8();
	}
}

class NorthPanel_ch9_8 extends JPanel{
	public NorthPanel_ch9_8() {
		setBackground(Color.LIGHT_GRAY);
		add(new JButton("열기"));
		add(new JButton("닫기"));
		add(new JButton("나가기"));
	}
}

class CenterPanel_ch9_8 extends JPanel{
	public CenterPanel_ch9_8() {
		setBackground(Color.WHITE);
		//setOpaque(true);
		setLayout(null);
		for(int i=0;i<10;i++) {
			JLabel jl = new JLabel("*");
			int x = (int) (Math.random() * 250);
			int y = (int) (Math.random() * 150);
			jl.setLocation(x, y);
			jl.setSize(20, 20);
			//jl.setBackground(Color.red);
			jl.setForeground(Color.red);
			add(jl);
		}
	}
}


class SouthPanel_ch9_8 extends JPanel{
	public SouthPanel_ch9_8() {
		setBackground(Color.YELLOW);
		add(new JButton("Word Input"));
		add(new JTextField(16));
	}
}
//20210505