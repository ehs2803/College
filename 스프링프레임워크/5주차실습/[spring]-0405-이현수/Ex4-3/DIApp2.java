package Ex4_2;

import org.springframework.context.support.GenericXmlApplicationContext;

import Ex4_2.OperatorBean;

public class DIApp2 {
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new 
		GenericXmlApplicationContext("classpath*:appcontext.xml");
		
		OperatorBean operator = (OperatorBean)ctx.getBean("operatorBean");
		
		double value = operator.calc();
		System.out.println("The result value: "+ value);
		ctx.close();
	}
}
