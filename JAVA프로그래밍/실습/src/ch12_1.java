import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ch12_1 extends JFrame {
	public ch12_1(){
		super("이미지 그리기 연습");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(new MyPanel_ch12_1());
		setSize(300,300);
		setVisible(true);
	}
	
	class MyPanel_ch12_1 extends JPanel {
		private ImageIcon icon = new ImageIcon("images/backiee-36622.jpg");
		private Image img = icon.getImage();
		private JButton button = new JButton("Hide/Show");
		private boolean showFlag = true;
		
		public MyPanel_ch12_1() {
			setLayout(new FlowLayout());
			add(button);
			
			button.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					showFlag = !showFlag; // true와 false의 토글
					MyPanel_ch12_1.this.repaint(); 
					// repaint()는 다시 paintComponent()가 호출되게 하여, 
					// showFlag가 true이면 그리고 false이면 그리지 않도록 함
				}				
			});
		}
		
		@Override
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			if(showFlag) // true이면 그리고 false이면 그리지 않음
				g.drawImage(img, 0, 0, getWidth(), getHeight(), this);			
		}
	}
	
	static public void main(String[] args) {
		new ch12_1();
	}
}