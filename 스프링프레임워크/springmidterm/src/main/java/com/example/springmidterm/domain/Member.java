package com.example.springmidterm.domain;

public class Member {
    private Long id;
    private String email;
    private String password;
    Enum<Role> role;

    public Member(String email, String password, Enum<Role> role) {
        this.email = email;
        this.password = password;
        this.role=role;
    }

    public Member(Long id, String email, String password, Enum<Role> role) {
        this.id = id;
        this.email = email;
        this.password = password;
        this.role = role;
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

    public Enum<Role> getRole() {
        return role;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setRole(Enum<Role> role) {
        this.role = role;
    }
}
