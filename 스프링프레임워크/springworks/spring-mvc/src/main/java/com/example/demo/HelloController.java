package com.example.demo;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HelloController {
	@GetMapping("/")
	public String hello(Model model) 
	{
		return "index";
	}
	
	@RequestMapping(value="/hello", method=RequestMethod.GET) 
	public String hello(Model model, @RequestParam(value = "name", required = false) String name) {
		model.addAttribute("greeting", "안녕하세요, "+ name);
		return "hello";
	}
	
	@RequestMapping(value="/login", method=RequestMethod.GET) 
	public String login() {
		return "login";
	}
	
	@RequestMapping(value="/logincheck", method=RequestMethod.GET) 
	public String logincheck(Model model, 
			@RequestParam(value = "id") String id,
			@RequestParam(value = "pwd") String pwd) {
		if(id.equals("abcd") && pwd.equals("1234")) {
			model.addAttribute("id", "id");
		}

		return "logincheck";
	}
}
