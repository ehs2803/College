import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch11_3 extends JFrame{
	public ch11_3() {
		super("Money Changer");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		setContentPane(new MyPanel());
		
		
		setSize(400,400);
		setVisible(true);
	}
	
	class MyPanel extends JPanel{
		private int [] unit = {50000,10000,1000,500,100,50,10,1};
		private String [] text = {"������", "����", "õ��","500��","100��","50��","10��","1��"};
		private JTextField source;
		private JTextField [] tf = new JTextField[8];
		public MyPanel() {
			setBackground(Color.pink);
			setLayout(null);
			
			// �ݾ� ���̺�
			JLabel la = new JLabel("�ݾ�");
			la.setHorizontalAlignment(JLabel.RIGHT);
			la.setSize(50, 20);
			la.setLocation(20, 20);
			add(la);
						
			// �ݾ��� �Է��ϴ� JTextField
			source = new JTextField(30);
			source.setSize(100, 20);
			source.setLocation(100, 20);
			add(source);
						
			// ��� ��ư
			JButton calcBtn = new JButton("���");
			calcBtn.setSize(70, 20);
			calcBtn.setLocation(210, 20);
			add(calcBtn);
			
			for(int i=0; i<text.length; i++) {
				la = new JLabel(text[i]);
				la.setHorizontalAlignment(JLabel.RIGHT);
				la.setSize(50, 20);
				la.setLocation(50, 50+i*20);
				add(la);
				tf[i] = new JTextField(30);
				tf[i].setHorizontalAlignment(JTextField.CENTER);
				tf[i].setSize(70, 20);
				tf[i].setLocation(120, 50+i*20);
				
				add(tf[i]);
			}
			// ��� ��ư�� Action ������
			calcBtn.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					String str = source.getText();
					if(str.length()==0) return;
					
					int money = Integer.parseInt(str);
					int res;
					for(int i=0;i<unit.length;i++) {
						res = money/unit[i];
						tf[i].setText(Integer.toString(res));
						if(res>0) money = money%unit[i];
					}
				}
			});
		}
	}
	public static void main(String[] args) {
		new ch11_3();
	}
}
