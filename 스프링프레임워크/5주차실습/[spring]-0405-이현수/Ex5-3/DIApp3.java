package Ex4_2;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class DIApp3 {
	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(JavaConfig.class);
		OperatorBean operator = (OperatorBean)ctx.getBean("operatorBean");
		
		double value = operator.calc();
		System.out.println("The result value: "+ value);
		ctx.close();
	}
}
