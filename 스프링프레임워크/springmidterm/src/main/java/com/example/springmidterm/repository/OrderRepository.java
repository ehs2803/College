package com.example.springmidterm.repository;

import com.example.springmidterm.domain.Item;
import com.example.springmidterm.domain.Order;

import java.util.List;
import java.util.Optional;

public interface OrderRepository {
    public Order save(Order order);
    public Optional<Order> findById(Long id);
    public List<Order> findAll();
    public void clearStore();
}
