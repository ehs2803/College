package com.example.springmidterm.service;

import com.example.springmidterm.domain.Item;
import com.example.springmidterm.domain.Member;
import com.example.springmidterm.domain.Order;
import com.example.springmidterm.domain.OrderItem;
import com.example.springmidterm.repository.ItemRepository;
import com.example.springmidterm.repository.MemberRepository;
import com.example.springmidterm.repository.OrderRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;
import java.util.List;

@Component
public class OrderService {
    private final ItemRepository itemRepository;
    private final OrderRepository orderRepository;

    @Autowired
    public OrderService(ItemRepository itemRepository, OrderRepository orderRepository) {
        this.itemRepository = itemRepository;
        this.orderRepository = orderRepository;
    }

    public Order createOrder(Long mid, List<OrderItem> orderItems) {
        LocalDateTime localDateTime = LocalDateTime.now();
        for(int i=0;i<orderItems.size();i++){
            int buyquantity = orderItems.get(i).getQuantity();
            itemRepository.reduceQuantityByOrder(orderItems.get(i).getCode(), buyquantity , mid, localDateTime);
        }
        Order order = new Order(mid, localDateTime, orderItems);
        orderRepository.save(order);
        return order;
    }

    public boolean IsvalidQuantity(String code, int quantity){
        Item item = itemRepository.findBycode(code).get();
        int itemquantity = item.getQuantity();
        if(itemquantity<quantity) return false;
        else return true;
    }
}