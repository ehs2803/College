import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class CardLayoutTest implements ActionListener{
	JPanel cards;
	public void createUI() {
		cards = new JPanel();
		
		JPanel card1 = new JPanel();
		card1.setBackground(Color.blue);
		JButton b1 = new JButton("Next");
		b1.setActionCommand("Next");
		b1.addActionListener(this);
		card1.add(b1);
		
		JPanel card2 = new JPanel();
		card2.setBackground(Color.yellow);
		JButton b2 = new JButton("prev");
		b2.setActionCommand("prev");
		b2.addActionListener(this);
		card2.add(b2);
		
		cards.setLayout(new CardLayout());
		cards.add(card1,"First");
		cards.add(card2,"Second");
	}
	public void actionPerformed(ActionEvent e) {
		CardLayout cl = (CardLayout)(cards.getLayout());
		String str = e.getActionCommand();
		
		if(str.equals("Next")) cl.show(cards,"Second");
		else if(str.equals("prev")) cl.show(cards,"First");
	}
	public static void main(String[] args) {
		JFrame f =new JFrame("Crad Layout");
		f.setSize(320,240);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		CardLayoutTest clt = new CardLayoutTest();
		clt.createUI();
		f.add(clt.cards);
		
		f.setVisible(true);
	}
}
