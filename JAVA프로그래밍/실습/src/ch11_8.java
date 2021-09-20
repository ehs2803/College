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

		File fp = new File("images");	//images 폴더를 가리키는 파일 포인터 fp
		File[] imageFiles = fp.listFiles();	//지정한 폴더에 있는 파일들을 File 배열에 저장
		for (File f : imageFiles) {
			if (f.isFile()) {
				ImageIcon icon = new ImageIcon(f.getPath()); //getPath는 파일 경로를 리턴
				imagesVector.add(icon);	//벡터에 이미지를 추가한다
			}
		}

		c.add(new MenuPanel(), BorderLayout.NORTH);
		imageLabel=new JLabel(imagesVector.get(0));	//초기에는 인덱스 0의 이미지를 보이도록
		c.add(imageLabel, BorderLayout.CENTER);
		imageLabel.addMouseListener(new MyMouseListener(0)); //이미지 레이블에 Mouse 리스너 추가

		setSize(500, 300);
		setVisible(true);
	}

	class MenuPanel extends JPanel {
		public MenuPanel() {
			setLayout(new FlowLayout());

			ButtonGroup g = new ButtonGroup();
			g.add(left);
			g.add(right);	//버튼 그룹에 라디오 버튼 추가

			add(left);
			add(right);
			
			left.setSelected(true);	//기본으로 left 버튼을 선택 상태로 함
		}
	}

	class MyMouseListener extends MouseAdapter {
		private int index;

		public MyMouseListener(int startIndex) {
			index = startIndex;
			//마우스 리스너 객체가 처음 생성될 때 지정한 시작 인덱스의 이미지를 초기 화면에 보인다
		}

		public void mouseReleased(MouseEvent e) {	//버튼을 눌렀다 뗐을 때
			if (left.isSelected()) {	//왼쪽 버튼이 선택된 상태이면
				index++;	//인덱스 증가
				if (index >= imagesVector.size())
					index = 0;
				//벡터 크기보다 크면 인덱스를 0으로 변경
			} else {	//오른쪽 버튼이 선택된 상태이면
				index--;	//인덱스 감소
				if (index == -1)
					index = imagesVector.size() - 1;
				//인덱스가 -1이 되면 인덱스 값을 최대로 변경
			}
			imageLabel.setIcon(imagesVector.get(index));
			//변경된 인덱스의 이미지를 이미지 라벨에 보이도록 설정
		}
	}

	public static void main(String[] args) {
		new ch11_8();
	}
}

