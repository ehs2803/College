import java.awt.*;
import javax.swing.*;
import java.util.*;
import java.io.*;

public class ch13_11 extends JFrame{
	Words words = new Words("words.txt"); // words.txt ������ ��� �ܾ �о� ���Ϳ� �����Ѵ�.
	JPanel jp = new JPanel();
	JTextField jf = new JTextField(10);
	NorthPanel np = new NorthPanel();
	CenterPanel cp = new CenterPanel();
	SouthPanel sp = new SouthPanel();
	public ch13_11() {
		super("�������� �ܾ� ���߱�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setContentPane(new RainPanel());
		
		setSize(400,400);
		setVisible(true);
	}
	
	class RainPanel extends JPanel{
		public RainPanel(){
			this.setLayout(new BorderLayout());
			add(np, BorderLayout.NORTH);
			add(cp, BorderLayout.CENTER);
			add(sp, BorderLayout.SOUTH);
		}
	}
	
	class NorthPanel extends JPanel{
		public NorthPanel() {
			add(jp);
		}
	}
	
	class CenterPanel extends JPanel{
		public CenterPanel() {
			
		}
	}
	
	class SouthPanel extends JPanel{
		public SouthPanel() {
			this.setBackground(Color.GRAY);
			add(jf);
		}
	}
	
	class RainThread extends Thread{
		public void run() {
			
		}
	}
	
	public static void main(String[] args) {
		new ch13_11();
	}
}

class Words {
	Vector<String> wordVector = new Vector<String>();

	public Words(String fileName) {
		try {
			Scanner scanner = new Scanner(new FileReader(fileName));
			while(scanner.hasNext()) { // ���� ������ ����
				String word = scanner.nextLine(); // �� ������ �а� '\n'�� ���� ������ ���ڿ��� ����
				wordVector.add(word); // ���ڿ��� ���Ϳ� ����
			}
			scanner.close();
		}
		catch(FileNotFoundException e) {
			System.out.println("file not found error");
			System.exit(0);
		}
	}
	
	public String getRandomWord() {
		final int WORDMAX = wordVector.size(); // �� �ܾ��� ����
		int index = (int)(Math.random()*WORDMAX);
		return wordVector.get(index);
	}	
}
