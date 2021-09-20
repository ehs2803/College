import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class CBItem implements ItemListener{
	public void itemStateChanged(ItemEvent e) {
		JCheckBox cb = (JCheckBox)e.getItemSelectable();
		Color bg = cb.getParent().getBackground();
		int r = bg.getRed();
		int g = bg.getGreen();
		int b = bg.getBlue();
		
		if(cb.getText().equals("빨간색")) {
			if(e.getStateChange()==ItemEvent.SELECTED) r=255;
			else if(e.getStateChange()==ItemEvent.DESELECTED) r=0;
		}
		if(cb.getText().equals("초록색")) {
			if(e.getStateChange()==ItemEvent.SELECTED) g=255;
			else if(e.getStateChange()==ItemEvent.DESELECTED) g=0;
		}
		if(cb.getText().equals("파란색")) {
			if(e.getStateChange()==ItemEvent.SELECTED) b=255;
			else if(e.getStateChange()==ItemEvent.DESELECTED) b=0;
		}
		
		cb.getParent().setBackground(new Color(r,g,b));
	}
}
public class ch12_5 {
	public static void main(String[] args) {
		JFrame f = new JFrame("JCheckBoxTest");
		f.setSize(320,240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setLayout(new FlowLayout());
		//f.setBackground(Color.BLACK);
		
		JCheckBox[] cb = new JCheckBox[3];
		cb[0] = new JCheckBox("빨간색");
		cb[1] = new JCheckBox("초록색");
		cb[2] = new JCheckBox("파란색");
	
		for(JCheckBox c:cb) {
			f.add(c);
			c.addItemListener(new CBItem());
		}	

		f.setVisible(true);
	}
}
