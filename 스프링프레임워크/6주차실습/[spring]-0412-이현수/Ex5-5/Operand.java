package Ex4_2;

import org.springframework.stereotype.Component;

@Component
public class Operand {
	double value=30;
	
	public Operand() { // 매개변수 있는 생성자면 오류남.
	}
	
	public void setValue(int value) {
		this.value=value;
	}
	
	public double getValue() {
		return value;
	}
}
