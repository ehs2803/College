package Ex4_2;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;

public class PlusOp implements OperatorBean {
	
	Operand operand1;
	Operand operand2;
	
	public PlusOp(Operand op1, Operand op2) {
		operand1 = op1;
		operand2 = op2;
	}
	
	public double calc() {
		return operand1.getValue()+operand2.getValue();
	}
	
	public Operand getOperand1() {
		return operand1;
	}
	public void setOperand1(Operand op) {
		operand1=op;
	}
	public Operand getOperand2() {
		return operand2;
	}
	public void setOperand2(Operand op) {
		operand2=op;
	}
}
