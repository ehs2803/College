package com.example.springmidterm.repository;

import com.example.springmidterm.domain.Member;
import com.example.springmidterm.domain.Role;
import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

public class FileMemberRepository implements MemberRepository, InitializingBean, DisposableBean {
    private static File memberfile = new File("member.txt");
    private static Map<Long, Member> store = new HashMap<>();
    private static long sequence;

    @Override
    public void afterPropertiesSet() throws Exception {
        if(memberfile.exists()) {
            BufferedReader inFile = new BufferedReader(new FileReader(memberfile));
            String sLine = null;
            long cnt=0L;
            while( (sLine = inFile.readLine()) != null ) {
                cnt++;
                String [] splitstr = sLine.split(" ");
                Member member;
                if(splitstr[3].equals("M")) member = new Member(Long.parseLong(splitstr[0]),splitstr[1], splitstr[2], Role.MANAGER);
                else member = new Member(Long.parseLong(splitstr[0]),splitstr[1], splitstr[2], Role.EMPLOYEE);
                store.put(member.getId(), member);
            }
            sequence = cnt;
            inFile.close();
        }
    }

    @Override
    public void destroy() throws Exception {
        try{
            BufferedWriter writer = new BufferedWriter(new FileWriter(memberfile));
            for (Map.Entry<Long, Member> entry : store.entrySet()) {
                Long key = entry.getKey();
                Member value = entry.getValue();
                String str = "";
                str+=Long.toString(key); str+=" ";
                str+=value.getEmail(); str+=" ";
                str+=value.getPassword(); str+=" ";
                if(value.getRole()==Role.MANAGER) str+="M";
                else str+="E";
                str+="\n";
                writer.write(str);
            }
            writer.close();
        } catch(IOException e){
            System.out.println("파일쓰기에 실패했습니다!!!");
        }
        System.out.println("계정정보를 파일에 정상적으로 저장했습니다.");
        System.out.println("=======================================");
    }
/*
    public void init() throws IOException {
        if(memberfile.exists()) {
            BufferedReader inFile = new BufferedReader(new FileReader(memberfile));
            String sLine = null;
            long cnt=0L;
            while( (sLine = inFile.readLine()) != null ) {
                cnt++;
                String [] splitstr = sLine.split(" ");
                Member member;
                if(splitstr[3].equals("M")) member = new Member(Long.parseLong(splitstr[0]),splitstr[1], splitstr[2], Role.MANAGER);
                else member = new Member(Long.parseLong(splitstr[0]),splitstr[1], splitstr[2], Role.EMPLOYEE);
                store.put(member.getId(), member);
            }
            sequence = cnt;
            inFile.close();
        }
    }

    public void saveTofile() throws IOException {
        try{
            BufferedWriter writer = new BufferedWriter(new FileWriter(memberfile));
            for (Map.Entry<Long, Member> entry : store.entrySet()) {
                Long key = entry.getKey();
                Member value = entry.getValue();
                String str = "";
                str+=Long.toString(key); str+=" ";
                str+=value.getEmail(); str+=" ";
                str+=value.getPassword(); str+=" ";
                if(value.getRole()==Role.MANAGER) str+="M";
                else str+="E";
                str+="\n";
                writer.write(str);
            }
            writer.close();
        } catch(IOException e){
            System.out.println("파일쓰기에 실패했습니다!!!");
        }
    }
*/
    @Override
    public Member save(Member member) {
        member.setId(++sequence);
        store.put(member.getId(), member);
        return member;
    }

    @Override
    public Optional<Member> findByEmail(String email) {
        return store.values().stream()
                .filter(member -> member.getEmail().equals(email))
                .findAny();
    }
}
