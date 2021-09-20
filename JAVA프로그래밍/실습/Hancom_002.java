import java.awt.Graphics;
import java.util.Calendar;
import java.util.GregorianCalendar;
 
import javax.swing.JFrame;
 
// �Ƴ��α� �ð�
public class Hancom_002 extends JFrame implements Runnable {
 
    private GregorianCalendar time;
 
    // frame ũ��
    private int width = 300;
 
    // time ����� ���� ����
    private int hour = 0;
    private int min = 0;
    private int sec = 0;
 
    private Graphics gp;
 
    // time�� ����� ������ Frame �� �̹����� �� ��ġ�ϱ� ���� �޼���
    public void paint(Graphics gp) {
 
        time = new GregorianCalendar();
 
        // �ð� ������ �����´�.
        min = time.get(Calendar.MINUTE);
        hour = time.get(Calendar.HOUR);
        sec = time.get(Calendar.SECOND);
 
        if (sec == 60) {
            sec = 0;
            min++;
        }
        if (min == 60) {
            min = 0;
            hour++;
        }
        if (min == 60 && hour == 12) {
            hour = 0;
        }
 
        // Frame ���ο� �׷��� ��� �κ��� �����.
        gp.clearRect(0, 0, width, width);
        
        // �ð� �׵θ��� ǥ���ϱ� ����
        rec_draw();
 
 
        // �� / �� / �� �ٴ��� �׸���.
        draw(150, 150, 150, 50, 100, sec * 6);
        draw(150, 150, 150, 50, 70, min * 6);
        draw(150, 150, 150, 50, 50, hour * 30 + min / 2);
    }
    
    // �ð� �׵θ��� ������ ǥ���ϱ� ���� �޼���
    public void rec_draw() {
        int j = 1;
        for (int i = 1; i <= 60; i++) {
            // 5 �� ������ �ð��� ǥ���ϸ�, ���� ũ�� ǥ���Ͽ� ������ �Ѵ�.
            if (i % 5 == 0) {
                draw_t(150, 50, i * 6, 3);
                draw_time(150, 50, i * 6, j + "");
                j++;
            } else {
                draw_t(150, 50, i * 6, 1);
            }
        }
    }
    
    // �ð� �׵θ��� ���� ǥ���ϱ� ���� �޼���
    public void draw_t(int x, int y, int angle, int width) {
        x = 150 + (int) (120 * Math.sin(angle * Math.PI / 180));
        y = 150 - (int) (120 * Math.cos(angle * Math.PI / 180));
        gp.fillRect(x, y, width, width);
    }
    
    // �ð� �׵θ� �κп� 5�� ������ �ð��� ǥ���ϱ� ���� �޼���
    public void draw_time(int x, int y, int angle, String i) {
        x = 147 + (int) (105 * Math.sin(angle * Math.PI / 180));
        y = 155 - (int) (100 * Math.cos(angle * Math.PI / 180));
        gp.drawString(i, x, y);
    }
 
    // �� / �� / �� �� ǥ���ϱ� ���� drawLine(���� �׸��� �޼���) ���
    public void draw(int ox, int oy, int x, int y, int l, int angle) {
        x = ox + (int) (l * Math.sin(angle * Math.PI / 180));
        y = oy - (int) (l * Math.cos(angle * Math.PI / 180));
        gp.drawLine(ox, oy, x, y);
    }
 
    // ������ ����
    public Hancom_002() {
        init();
    }
 
    // frame�� �׸��� ���� �ʱ�ȭ �޼���
    public void init() {
        this.setTitle("Test Clock");
        this.setSize(width, width);
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        gp = getGraphics();
    }
 
    @Override
    public void run() {
        // TODO Auto-generated method stub
        while (true) {
            try {
                Thread.sleep(1000); // 1�ʸ���
                repaint();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
 
    public static void main(String[] args) {
        Hancom_002 h2 = new Hancom_002();
        Thread th = new Thread(h2);
        th.start();
    }
}