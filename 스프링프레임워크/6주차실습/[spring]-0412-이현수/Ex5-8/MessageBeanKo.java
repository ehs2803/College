package sample3;

import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

public class MessageBeanKo implements MessageBean{
	public void sayHello(String name) {
		System.out.println("안녕하세요, "+ name);
	}
	
	public void initMessage() {
		System.out.println("initMessage()실행");
	}
	
	public void finishMessage() {
		System.out.println("finishMessage()실행");
	}
}
