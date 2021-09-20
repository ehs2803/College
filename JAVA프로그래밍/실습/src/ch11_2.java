import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch11_2 extends JFrame{
	public ch11_2() {
		super("JTextField and JComboBox Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JTextField tf = new JTextField(10);
		JComboBox<String> strCombo = new JComboBox<String>();
		
		c.add(tf); c.add(strCombo);
		
		tf.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JTextField t = (JTextField)e.getSource();
				strCombo.addItem(t.getText());
				t.setText("");
			}
		});
		setSize(400,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ch11_2();
	}
}
