import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
public class ch11_6 extends JFrame{
	private JTextArea ta = new JTextArea(4, 24);
	private JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 100, 0);
	
	public ch11_6() {
		super("TextArea Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.add(ta);

		slider.setMajorTickSpacing(20);
		slider.setMinorTickSpacing(5);
		slider.setPaintLabels(true);
		slider.setPaintTicks(true);
		slider.setPaintTrack(true);
		c.add(slider);
		
		ta.addKeyListener(new MyKeyListener_ch11_6());
		slider.addChangeListener(new MyChangeListener_ch11_6());

		setSize(400,200);
		setVisible(true);
	}
	class MyKeyListener_ch11_6 extends KeyAdapter {
		public void keyTyped(KeyEvent e) {
			JTextArea t = (JTextArea) e.getSource();
			String s = t.getText();
			if (s.length() <= 100)	//텍스트 길이가 100이하이면
				slider.setValue(s.length());	//슬라이더의 값 증가
			else {	//텍스트 길이가 100 초과면
				s = s.substring(0, 99);
				t.setText(s);	//100 글자까지만 쓰이도록
			}
		}
	}

	class MyChangeListener_ch11_6 implements ChangeListener {
		public void stateChanged(ChangeEvent e) {
			JSlider js = (JSlider) e.getSource();
			String currentString = ta.getText();
			int textLength = currentString.length();	//현재 텍스트 길이
			if (textLength > js.getValue()) { // 슬라이더 값을 감소시켰으면
				currentString = currentString.substring(0, js.getValue());
				ta.setText(currentString);
			} else // 슬라이더 값을 증가시켰으면
				js.setValue(textLength); // 원상태로
		}
	}

	public static void main(String[] args) {
		new ch11_6();
	}
}
