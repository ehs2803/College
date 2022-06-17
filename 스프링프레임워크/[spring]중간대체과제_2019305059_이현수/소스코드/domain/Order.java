package com.example.springmidterm.domain;

import java.time.LocalDateTime;
import java.util.Calendar;
import java.util.List;

public class Order {
    private Long id;
    private Long mid;
    private LocalDateTime date;
    private List<OrderItem> orderItems;

    public Order(Long id, Long mid, LocalDateTime date, List<OrderItem> orderItems) {
        this.id = id;
        this.mid = mid;
        this.date = date;
        this.orderItems = orderItems;
    }

    public Order(Long mid, LocalDateTime date, List<OrderItem> orderItems) {
        this.mid = mid;
        this.date = date;
        this.orderItems = orderItems;
    }

    public Long getId() {
        return id;
    }

    public Long getMid() {
        return mid;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public List<OrderItem> getOrderItems() {
        return orderItems;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setMid(Long mid) {
        this.mid = mid;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public void setOrderItems(List<OrderItem> orderItems) {
        this.orderItems = orderItems;
    }
}
