import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class CBAction implements ActionListener{
	public void actionPerformed(ActionEvent e) {
		JComboBox cb = (JComboBox)e.getSource();
		String colorName = (String)cb.getSelectedItem();
		
		if(colorName.equals("�Ͼ��")) cb.getParent().setBackground(Color.WHITE);
		else if(colorName.equals("������")) cb.getParent().setBackground(Color.RED);
		else if(colorName.equals("�Ķ���")) cb.getParent().setBackground(Color.BLUE);
		else if(colorName.equals("������")) cb.getParent().setBackground(Color.BLACK);
	}
}
public class ch12_7 {
	public static void main(String[] args) {
		JFrame f = new JFrame("JComboBoxTest");
		f.setSize(320,240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setLayout(new FlowLayout());
		
		String[] Items = {"�Ͼ��","������","�Ķ���","������"};
		JComboBox cb = new JComboBox(Items);
		
		f.add(cb);
		
		cb.addActionListener(new CBAction());
		
		f.setVisible(true);
	}
}
