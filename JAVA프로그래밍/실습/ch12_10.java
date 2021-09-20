import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ch12_10 extends JFrame {
	JTextField tf1 = new JTextField(10);
	JButton btn = new JButton("변환");
	JTextField tf2 = new JTextField(20);
	
	public ch12_10() {
		setTitle("c");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setBackground(Color.GRAY);
		c.setLayout(new FlowLayout());
		
		c.add(new JLabel("이진수로 변환할 십진수를 입력하시오."));
		c.add(tf1);
		c.add(btn);
		c.add(tf2);
		
		btn.addActionListener(new Convert());
		setSize(300,200);
		setVisible(true);
	}
	class Convert implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			int temp = Integer.parseInt(tf1.getText());
			tf2.setText(converttoBinary(temp));
		}
	}
	String converttoBinary(int n) {
		String temp="";
		if(n==1) return "1";
		while(true) {
			int a = n%2;
			n = n/2;
			
			temp= Integer.toString(a)+temp;
			if(n==1) {
				temp=Integer.toString(1)+temp;
				break;
			}
		}
		return temp;
	}
	public static void main(String[] args) {
		new ch12_10();
	}
}


