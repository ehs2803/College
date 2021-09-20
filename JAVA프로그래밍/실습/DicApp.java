import java.util.Scanner;

class Dictionary {
    private static String [] kor = { "»ç¶û", "¾Æ±â", "µ·", "¹Ì·¡", "Èñ¸Á" };
    private static String [] eng = { "love", "baby", "money", "future", "hope" };
    public static String kor2Eng(String word) {
    	for(int i=0;i<kor.length;i++) {
    		if(word.equals(kor[i])) {
    			return eng[i];
    		}
    	}
    	return null;
    }
    public void run() {
    	Scanner sc = new Scanner(System.in);
    	System.out.println("welcome tk kor-Eng dic...");
    	while(true) {
    		System.out.print("korean word? ");
    		String word = sc.next();
    		if(word.equals("stop")) break;
    		String an = kor2Eng(word);
    		if(an==null) {
    			System.out.println(word+"dose not exist in my dictionary");
    		}
    		else {
    			System.out.println(word+"is "+an);
    		}
    	}
    	sc.close();
    	System.out.println("program stop");
    }
}

public class DicApp {
	public static void main(String[] args) {
		Dictionary dc = new Dictionary();
		dc.run();
	}
}
