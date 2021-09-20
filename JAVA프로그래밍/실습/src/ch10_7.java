import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch10_7 extends JFrame{
	public ch10_7() {
		super("마우스 휠을 굴려 폰트 크기 조절");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    Container c = getContentPane();
	    c.setLayout(new FlowLayout());
	    
	    JLabel label = new JLabel("Love Java");
	    label.setFont(new Font("Arial",Font.PLAIN,10));
		c.add(label);
	    
		label.addMouseWheelListener(new MouseWheelListener() {
			public void mouseWheelMoved(MouseWheelEvent e) {
				int n = e.getWheelRotation();
				if(n<0) { //up direction
					JLabel la = (JLabel)e.getSource();
					Font f = la.getFont();
					int size = f.getSize();
					if(size-5>=5) la.setFont(new Font("Arial", Font.PLAIN, size-5));
					
				}
				else { //down direction
					JLabel la = (JLabel)e.getSource();
					Font f = la.getFont();
					int size = f.getSize();
					la.setFont(new Font("Arial", Font.PLAIN, size+5));
				}
			}
		});
	    
	
		
	    setSize(400,200);
	    setVisible(true);
	}
	public static void main(String[] args) {
		new ch10_7();
	}
}
//20210507