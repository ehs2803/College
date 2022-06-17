package com.example.springmidterm.service;

import com.example.springmidterm.domain.Item;
import com.example.springmidterm.repository.ItemRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

@Component
public class InventoryService {
    private final ItemRepository itemRepository;

    @Autowired
    public InventoryService(ItemRepository itemRepository){
        this.itemRepository=itemRepository;
    }

    public Item addItem(Item item){
        return itemRepository.save(item);
    }

    public Item updateItem(String code, int quantity, Long mid, LocalDateTime localDateTime){
        return itemRepository.updateQuantity(code, quantity, mid, localDateTime);
    }

    public Item updateItem(String code, Item updateParam){
        return itemRepository.update(code, updateParam);
    }

    public Optional<Item> findByCode(String code){
        return itemRepository.findBycode(code);
    }

    public List<Item> allItem(){
        return itemRepository.findAll();
    }

    public boolean validateDuplicateItem(String code) {
        if(itemRepository.findBycode(code).isPresent()){
            return true;
        }
        else return false;
    }
}
