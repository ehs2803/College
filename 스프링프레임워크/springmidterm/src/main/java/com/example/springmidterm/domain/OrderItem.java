package com.example.springmidterm.domain;

public class OrderItem {
    private Long oid;
    private String code;
    private int quantity;

    public OrderItem(Long oid, String code, int quantity) {
        this.oid = oid;
        this.code = code;
        this.quantity = quantity;
    }

    public OrderItem(String code, int quantity) {
        this.code = code;
        this.quantity = quantity;
    }

    public Long getOid() {
        return oid;
    }

    public String getCode() {
        return code;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setOid(Long oid) {
        this.oid = oid;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void setquantity(int quantity) {
        this.quantity = quantity;
    }
}
