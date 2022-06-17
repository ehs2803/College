package Ex6_1;

import org.springframework.context.support.GenericXmlApplicationContext;

public class HelloApp {
	public static void main(String[] args) {
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext("classpath:appctxEx6_2.xml");
		MessageBean msgBean = (MessageBean)ctx.getBean("proxy");
		msgBean.sayHello();
		ctx.close();
	}
}
