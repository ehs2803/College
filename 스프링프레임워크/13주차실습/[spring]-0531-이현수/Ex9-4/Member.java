package com.example.demo;
import java.time.LocalDateTime;

public class Member {
	private Long id;
	private String email;
	private String password;
	private String name;
	private LocalDateTime registerDateTime;
	public Member(String email, String password, String name, LocalDateTimeregDateTime) {
		this.email = email;
		this.password = password;
		this.name = name;
		this.registerDateTime = regDateTime;
	}

	public getId() { return id; }
	public getEmail(){return email;}
	public getPassword(){return password;}
	public getName(){return name;}
	public getRegisterDateTime(){ return registerDateTime;}
	
	public setId(Long id){ this.id = id;}
	public setEmail(String email){ this.email = email;}
	public setPassword(String password){ this.password = password;}
	public setName(String name) { this.name=name;}
	public setRegisterDatetime(LocalDateTime registerDateTime){ this.registerDatetime = registerDateTime;}
}