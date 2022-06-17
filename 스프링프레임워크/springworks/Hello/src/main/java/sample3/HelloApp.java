package sample3;

import org.springframework.context.support.GenericXmlApplicationContext;

public class HelloApp {
	//public static void main(String[] args) {
		//GenericXmlApplicationContext ctx = new GenericXmlApplicationContext("classpath*:applicationContext.xml");
		//MessageBean bean = (MessageBean)ctx.getBean("messageBean");
		//bean.sayHello("Spring이현수");
		//ctx.close();
	//}
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">

<bean id="messageBean" class="sample3.MessageBeanKo">
</bean>

</beans>
*/