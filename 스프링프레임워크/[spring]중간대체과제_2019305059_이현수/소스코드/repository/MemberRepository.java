package com.example.springmidterm.repository;

import com.example.springmidterm.domain.Member;

import java.io.IOException;
import java.util.List;
import java.util.Optional;

public interface MemberRepository {
    Member save(Member member);
    Optional<Member> findByEmail(String email);
}
