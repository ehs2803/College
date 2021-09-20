import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;

public class ch11_7 extends JFrame{
	private JSlider slider = new JSlider(1,100,50);
	private JLabel label = new JLabel("   I Love Java   ");
	
	public ch11_7() {
		super("JSlider Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new BorderLayout());		
		c.add(slider, BorderLayout.NORTH);
		c.add(label, BorderLayout.CENTER);
		
		slider.setMajorTickSpacing(20);
		slider.setMinorTickSpacing(5);
		slider.setPaintLabels(true);
		slider.setPaintTicks(true);
		
		label.setHorizontalAlignment(JLabel.CENTER);
		label.setOpaque(true);
		label.setFont(new Font("TimesRoman", Font.PLAIN, slider.getValue()));		

		slider.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e) {
				JSlider s = (JSlider)e.getSource();
				label.setFont(new Font("TimesRoman", Font.PLAIN, s.getValue()));
			}
		});
		
		setSize(400,200);
		setVisible(true);
	}
	public static void main(String [] args) {
		new ch11_7();
	}
}
