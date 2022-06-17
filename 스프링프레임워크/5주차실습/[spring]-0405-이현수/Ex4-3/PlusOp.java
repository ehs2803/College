package Ex4_2;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;

public class PlusOp implements OperatorBean {
	
	@Autowired
	@Qualifier("operand1")
	Operand operand1;
	@Autowired
	@Qualifier("operand2")
	Operand operand2;
	
	public PlusOp(Operand op1, Operand op2) {
		operand1 = op1;
		operand2 = op2;
	}
	
	public double calc() {
		return operand1.getValue()+operand2.getValue();
	}
}
