package Ex6_1;

import org.springframework.context.support.GenericXmlApplicationContext;

public class HelloApp {
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext("classpath:appctxEx6_1.xml");
		MessageBean msgBean = (MessageBean)ctx.getBean("messageBean");
		msgBean.sayHello();
		ctx.close();
	}
}
