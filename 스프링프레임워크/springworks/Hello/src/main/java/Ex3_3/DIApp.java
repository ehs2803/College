package Ex3_3;

import org.springframework.context.support.GenericXmlApplicationContext;

import Ex3_2_2.MessageBean;

public class DIApp {
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new 
		GenericXmlApplicationContext("classpath*:applicationContext.xml");
		OperatorBean operator = (OperatorBean)ctx.getBean("operatorBean");
		double value = operator.calc();
		System.out.println("The result value: "+ value);
		ctx.close();
	}
}
