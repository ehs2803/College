package spring;


import java.sql.Timestamp;
import java.util.Date;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class MainEx7_6 {
	private static MemberDao memberDao;
	public static void main(String[] args) {
	AbstractApplicationContext ctx = new
	GenericXmlApplicationContext("classpath:appCtx7_3.xml");
	memberDao = ctx.getBean("memberDao", MemberDao.class);
	// 새 멤버 추가 테스트, 실행할 때마다 email 값을 변경하여야 함
	Member member = new Member("guest1@gmail.com", "aaa", "Mr.Lee", new Timestamp(System.currentTimeMillis())); 
	memberDao.insert(member);
	System.out.println(member.getId());
	}
}
