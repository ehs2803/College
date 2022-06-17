package com.example.springmidterm.service;

import com.example.springmidterm.domain.Member;
import com.example.springmidterm.repository.MemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.util.List;
import java.util.Optional;

@Component
public class MemberService {

    private final MemberRepository memberRepository;

    @Autowired
    public MemberService(MemberRepository memberRepository){
        this.memberRepository=memberRepository;
    }

    public Long join(Member member) {
        memberRepository.save(member);
        return member.getId();
    }

    public Optional<Member> findByEmail(String email){
        return memberRepository.findByEmail(email);
    }

    public boolean validateDuplicateMember(String email) {
        if(memberRepository.findByEmail(email).isPresent()){
            return true;
        }
        else return false;
    }
}
