package spring;

import java.time.LocalDateTime;
import java.util.Date;

public class Member {

	private Long id;
	private String email;
	private String password;
	private String name;
	private Date registerDateTime;

	public Member(String email, String password, 
			String name, Date regDateTime) {
		this.email = email;
		this.password = password;
		this.name = name;
		this.registerDateTime = regDateTime;
	}



	void setId(Long id) {
		this.id = id;
	}

	public Long getId() {
		return id;
	}

	public String getEmail() {
		return email;
	}

	public String getPassword() {
		return password;
	}

	public String getName() {
		return name;
	}

	public Date getRegisterDateTime() {
		return registerDateTime;
	}

	public void changePassword(String oldPassword, String newPassword) throws Exception{
		if (!password.equals(oldPassword))
		throw new Exception("IdPasswordNotMatchingException");
		this.password = newPassword;
		}

}
