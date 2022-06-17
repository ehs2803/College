package spring;

import java.time.LocalDateTime;
import java.util.Date;

public class MemberRegisterService {
	private MemberDao memberDao;

	public MemberRegisterService(MemberDao memberDao) {
		this.memberDao = memberDao;
	}

	public void regist(RegisterRequest req) throws Exception {
		Member member = memberDao.selectByEmail(req.getEmail());
		if (member != null) {
		throw new Exception("dup email " + req.getEmail()); }
		Member newMember = new Member(req.getEmail(), req.getPassword(), req.getName(), new Date());
		memberDao.insert(newMember);
		}
}
