import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.util.Vector;

public class ch11_8 extends JFrame {
	private JRadioButton left = new JRadioButton("left");
	private JRadioButton right = new JRadioButton("right");
	private JLabel imageLabel;
	private Vector<ImageIcon> imagesVector = new Vector<ImageIcon>();

	public ch11_8() {
		setTitle("Image Gallery Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new BorderLayout());

		File fp = new File("images");	//images ������ ����Ű�� ���� ������ fp
		File[] imageFiles = fp.listFiles();	//������ ������ �ִ� ���ϵ��� File �迭�� ����
		for (File f : imageFiles) {
			if (f.isFile()) {
				ImageIcon icon = new ImageIcon(f.getPath()); //getPath�� ���� ��θ� ����
				imagesVector.add(icon);	//���Ϳ� �̹����� �߰��Ѵ�
			}
		}

		c.add(new MenuPanel(), BorderLayout.NORTH);
		imageLabel=new JLabel(imagesVector.get(0));	//�ʱ⿡�� �ε��� 0�� �̹����� ���̵���
		c.add(imageLabel, BorderLayout.CENTER);
		imageLabel.addMouseListener(new MyMouseListener(0)); //�̹��� ���̺� Mouse ������ �߰�

		setSize(500, 300);
		setVisible(true);
	}

	class MenuPanel extends JPanel {
		public MenuPanel() {
			setLayout(new FlowLayout());

			ButtonGroup g = new ButtonGroup();
			g.add(left);
			g.add(right);	//��ư �׷쿡 ���� ��ư �߰�

			add(left);
			add(right);
			
			left.setSelected(true);	//�⺻���� left ��ư�� ���� ���·� ��
		}
	}

	class MyMouseListener extends MouseAdapter {
		private int index;

		public MyMouseListener(int startIndex) {
			index = startIndex;
			//���콺 ������ ��ü�� ó�� ������ �� ������ ���� �ε����� �̹����� �ʱ� ȭ�鿡 ���δ�
		}

		public void mouseReleased(MouseEvent e) {	//��ư�� ������ ���� ��
			if (left.isSelected()) {	//���� ��ư�� ���õ� �����̸�
				index++;	//�ε��� ����
				if (index >= imagesVector.size())
					index = 0;
				//���� ũ�⺸�� ũ�� �ε����� 0���� ����
			} else {	//������ ��ư�� ���õ� �����̸�
				index--;	//�ε��� ����
				if (index == -1)
					index = imagesVector.size() - 1;
				//�ε����� -1�� �Ǹ� �ε��� ���� �ִ�� ����
			}
			imageLabel.setIcon(imagesVector.get(index));
			//����� �ε����� �̹����� �̹��� �󺧿� ���̵��� ����
		}
	}

	public static void main(String[] args) {
		new ch11_8();
	}
}

