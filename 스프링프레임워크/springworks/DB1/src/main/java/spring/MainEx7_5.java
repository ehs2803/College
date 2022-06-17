package spring;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class MainEx7_5 {
		private static MemberDao memberDao;
		public static void main(String[] args) {
			AbstractApplicationContext ctx = new GenericXmlApplicationContext("classpath:appCtx7_3.xml");
			memberDao = ctx.getBean("memberDao", MemberDao.class);
			
			Member member = memberDao.selectByEmail("madvirus@madvirus.net");	
			try { member.changePassword("1234", "aaaa"); // (oldpassword, newpassword)
			} catch (Exception e) { e.printStackTrace(); }
			
			memberDao.update(member);
			member = memberDao.selectByEmail("madvirus@madvirus.net");
			System.out.println(member.getPassword());
			System.out.println(memberDao.count());
			ctx.close();
	}

}
