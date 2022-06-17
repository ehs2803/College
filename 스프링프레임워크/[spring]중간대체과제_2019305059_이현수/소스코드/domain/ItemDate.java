package com.example.springmidterm.domain;

import java.time.LocalDateTime;
import java.util.Calendar;
import java.util.Date;

public class ItemDate {
    private String code;
    private Long mid;
    private LocalDateTime date;
    private int quantity;

    public ItemDate(String code, Long mid, LocalDateTime date, int quantity) {
        this.code = code;
        this.mid = mid;
        this.date = date;
        this.quantity = quantity;
    }

    public String getCode() {
        return code;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public Long getMid(){return mid;}

    public void setMid(Long mid){ this.mid=mid; }

    public int getQuantity() {
        return quantity;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
}
