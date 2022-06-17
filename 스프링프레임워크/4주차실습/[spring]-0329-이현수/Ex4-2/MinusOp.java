package Ex4_2;

import org.springframework.beans.factory.annotation.Autowired;

public class MinusOp implements OperatorBean{
	@Autowired
	Operand operand1;
	@Autowired
	Operand operand2;
	
	public MinusOp(Operand op1, Operand op2) {
		operand1 = op1;
		operand2 = op2;
	}
	
	public double calc() {
		return operand1.getValue()-operand2.getValue();
	}
}
