import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch11_1 extends JFrame{
	public ch11_1() {
		super("checkBox Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JCheckBox ch1 = new JCheckBox("버튼 비활성화");
		JCheckBox ch2 = new JCheckBox("버튼 감추기");
		JButton btn = new JButton("test button");
		
		c.add(ch1); c.add(ch2); c.add(btn);
		
		ch1.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange()==ItemEvent.SELECTED) {
					btn.setEnabled(false);
				}
				else {
					btn.setEnabled(true);
				}
			}
		});
		
		ch2.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange()==ItemEvent.SELECTED) {
					btn.setVisible(false);
				}
				else {
					btn.setVisible(true);
				}
			}
		});
		setSize(300,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch11_1();
	}
}
