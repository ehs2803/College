import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class RBAction implements ActionListener{
	public void actionPerformed(ActionEvent e) {
		JRadioButton rb = (JRadioButton)e.getSource();
		
		if(e.getActionCommand().equals("하얀색")) rb.getParent().setBackground(Color.WHITE);
		else if(e.getActionCommand().equals("빨간색")) rb.getParent().setBackground(Color.RED);
		else if(e.getActionCommand().equals("파란색")) rb.getParent().setBackground(Color.BLUE);
		else if(e.getActionCommand().equals("검은색")) rb.getParent().setBackground(Color.BLACK);
	}
}
public class ch12_6 {
	public static void main(String[] args) {
		JFrame f = new JFrame("JRadioButtonTest");
		f.setSize(320,240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setLayout(new FlowLayout());
		
		ButtonGroup grp = new ButtonGroup();
		JRadioButton[] rb = new JRadioButton[4];
		rb[0]=new JRadioButton("하얀색");
		rb[1]=new JRadioButton("빨간색");
		rb[2]=new JRadioButton("파란색");
		rb[3]=new JRadioButton("검은색");
		
		for(JRadioButton c:rb) {
			grp.add(c);
			f.add(c);
			c.setActionCommand(c.getText());
			c.addActionListener(new RBAction());
		}	

		f.setVisible(true);
	}
}
