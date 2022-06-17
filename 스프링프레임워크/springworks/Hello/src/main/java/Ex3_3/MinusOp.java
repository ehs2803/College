package Ex3_3;

public class MinusOp implements OperatorBean{
	double operand1, operand2;
	
	public MinusOp(double op1, double op2) {
		operand1 = op1;
		operand2 = op2;
	}
	
	public double calc() {
		return operand1-operand2;
	}
}
