import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch10_5 extends JFrame{
	public ch10_5() {
		super("Left 키로 문자열 이동");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JLabel jl = new JLabel("Love Java");
		jl.setFont(new Font("Arial",Font.PLAIN,10));
		c.add(jl);
		
		jl.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyChar() == '+') {
					JLabel la = (JLabel)e.getSource();
					Font f = la.getFont();
					int size = f.getSize();
					la.setFont(new Font("Arial", Font.PLAIN, size+5));
				}
				else if(e.getKeyChar()=='-') {
					JLabel la = (JLabel)e.getSource();
					Font f = la.getFont();
					int size = f.getSize();
					if(size-5>=5) la.setFont(new Font("Arial", Font.PLAIN, size-5));
				}
			}
		});
		
		setSize(400,200);
		setVisible(true);
		jl.setFocusable(true);
		jl.requestFocus();
	}
	public static void main(String [] args) {
		new ch10_5();
	}
}
//20210507