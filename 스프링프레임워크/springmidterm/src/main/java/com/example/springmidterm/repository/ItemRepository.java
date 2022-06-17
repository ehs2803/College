package com.example.springmidterm.repository;

import com.example.springmidterm.domain.Item;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

public interface ItemRepository {
    public Item save(Item item);
    public Optional<Item> findBycode(String code);
    public List<Item> findAll();
    public Item update(String code, Item updateParam);
    public Item updateQuantity(String code, int quantity, Long mid, LocalDateTime localDateTime);
    public Item reduceQuantityByOrder(String code, int quantity, Long mid, LocalDateTime localDateTime);
    public void clearStore();
}
