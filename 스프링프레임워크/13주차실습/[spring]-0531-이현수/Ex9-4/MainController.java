package com.example.demo;
import java.util.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
public class MainController {
	@Autowired
	private MemberDao memberDao;

	@GetMapping(value="/list")
	public String list(Model model) { 
		List<Member> memberList = memberDao.selectAll();
		model.addAttribute("members", memberList);
		return "list";
	}
}