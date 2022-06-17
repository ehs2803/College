import java.util.*;
import org.springframework.context.support.*;
import myapp.domain.*;
import myapp.dao.*;
import myapp.service.*;

public class MyBatis3Main {
	public static void main(String[] args) throws Exception {
		AbstractApplicationContext ctx = new GenericXmlApplicationContext("classpath:applicationContext.xml");
		UserService userService = (UserService)ctx.getBean("userService");  
		// save.
		User user = new User();  
		user.setName("mybatis");  
		user.setPhone("123456789");  
		user.setBirthday(new Date());  
		userService.save(user);  
		System.out.println("save ok");
		// query all records.
		List<User> users = userService.getAll();
		for(int i = 0 ; i < users.size(); ++i ) System.out.println(users.get(i));
	}
}