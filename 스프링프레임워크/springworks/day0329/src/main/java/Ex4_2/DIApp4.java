package Ex4_2;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class DIApp4 {
	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(JavaConfig.class);
		OperatorBean operator = (OperatorBean)ctx.getBean("operatorBean");
		Operand op1 = operator.getOperand1();
		Operand op2 = operator.getOperand2();
		System.out.println("op1: "+op1+", op2: "+op2);
		ctx.close();
	}
}
