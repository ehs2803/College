import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

public class ch11_5 extends JFrame{
	public ch11_5() {
		super("JSlider Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JSlider slider = new JSlider(JSlider.HORIZONTAL, 100,200,140);
		slider.setPaintLabels(true);
		slider.setPaintTicks(true);
		slider.setPaintTrack(true);
		slider.setMajorTickSpacing(20);
		c.add(slider);
		
		JLabel la = new JLabel(Integer.toString(slider.getValue()));
		la.setOpaque(true);
		la.setBackground(Color.green);
		c.add(la);
		
		slider.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e) {
				JSlider s = (JSlider)e.getSource();
				la.setText(Integer.toString(s.getValue()));
			}
		});
		
		setSize(400,200);
		setVisible(true);
	}
	public static void main(String [] args) {
		new ch11_5();
	}
}
