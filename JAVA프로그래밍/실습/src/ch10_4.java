import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch10_4 extends JFrame{
	public ch10_4() {
		super("Left 키로 문자열 이동");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JLabel jl = new JLabel("Love Java");
		c.add(jl);
		
		jl.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_LEFT) {
					JLabel la = (JLabel)e.getSource();
					String text = la.getText();
					String s = text.substring(1)+text.substring(0,1);
					la.setText(s);
				}
			}
		});
		
		setSize(400,200);
		setVisible(true);
		jl.setFocusable(true);
		jl.requestFocus();
	}
	public static void main(String[] args) {
		new ch10_4();
	}
}
//20210507