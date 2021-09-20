import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch10_3 extends JFrame{
	public ch10_3() {
		super("Left키로 문자열 교체");
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
					StringBuffer text  = new StringBuffer(la.getText());
					la.setText(text.reverse().toString());
				}
			}
		});
		
		setSize(400,200);
		setVisible(true);
		jl.setFocusable(true);
		jl.requestFocus();
	}
	public static void main(String[] args) {
		new ch10_3();
	}
}
//20210507