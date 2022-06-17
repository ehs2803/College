package com.example.springmidterm;


import com.example.springmidterm.repository.*;
import com.example.springmidterm.service.InventoryService;
import com.example.springmidterm.service.MemberService;
import com.example.springmidterm.service.OrderService;
import com.example.springmidterm.service.StatisticalService;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class JavaConfig {
    @Bean
    public StatisticalService statisticalService(){return new StatisticalService(itemRepository(), orderRepository());}

    @Bean
    public OrderService orderService(){return new OrderService(itemRepository(),orderRepository());}

    @Bean
    public InventoryService inventoryService(){
        return new InventoryService(itemRepository());
    }

    @Bean
    public MemberService memberService() {
        return new MemberService(memberRepository());
    }

    @Bean
    public OrderRepository orderRepository(){return new FileOrderRepository();}

    @Bean
    public ItemRepository itemRepository(){
        return new FileItemRepository();
    }

    @Bean
    public MemberRepository memberRepository() {
        return new FileMemberRepository();
    }
}
