package com.example.springmidterm.repository;

import com.example.springmidterm.domain.*;
import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

import java.io.*;
import java.time.LocalDateTime;
import java.util.*;

public class FileOrderRepository implements OrderRepository, InitializingBean, DisposableBean {
    private static File orderfile = new File("order.txt");
    private static File orderitemfile = new File("orderitem.txt");
    private static Map<Long, Order> store = new HashMap<>();
    private static long sequence;

    @Override
    public void afterPropertiesSet() throws Exception {
        if(orderfile.exists() && orderitemfile.exists()) {
            BufferedReader inFile_orderfile = new BufferedReader(new FileReader(orderfile));
            BufferedReader inFile_orderitemfile = new BufferedReader(new FileReader(orderitemfile));
            String sLine = null;
            long cnt=0L;
            while( (sLine = inFile_orderfile.readLine()) != null ) {
                cnt++;
                String [] splitstr = sLine.split(" ");
                LocalDateTime localDateTime = LocalDateTime.of(Integer.parseInt(splitstr[2]),
                        Integer.parseInt(splitstr[3]),Integer.parseInt(splitstr[4]),
                        Integer.parseInt(splitstr[5]),Integer.parseInt(splitstr[6]),Integer.parseInt(splitstr[7]));
                Order order = new Order(Long.parseLong(splitstr[0]),Long.parseLong(splitstr[1]),
                        localDateTime, new ArrayList<OrderItem>());
                store.put(Long.parseLong(splitstr[0]), order);
            }
            sequence = cnt;
            while( (sLine = inFile_orderitemfile.readLine()) != null ) {
                String [] splitstr = sLine.split(" ");
                OrderItem orderItem = new OrderItem(Long.parseLong(splitstr[0]), splitstr[1],
                        Integer.parseInt(splitstr[2]));
                Order order = store.get(Long.parseLong(splitstr[0]));
                List<OrderItem> orderItems = order.getOrderItems();
                orderItems.add(orderItem);
                order.setOrderItems(orderItems);
                store.put(Long.parseLong(splitstr[0]), order);
            }
            inFile_orderfile.close();
            inFile_orderitemfile.close();
        }
    }


    @Override
    public void destroy() throws Exception {
        try{
            BufferedWriter writer_orderfile = new BufferedWriter(new FileWriter(orderfile));
            BufferedWriter writer_orderitemfile = new BufferedWriter(new FileWriter(orderitemfile));
            for(Map.Entry<Long, Order> entry : store.entrySet()){
                Long key = entry.getKey();
                Order value = entry.getValue();
                List<OrderItem> orderItems = value.getOrderItems();
                String str="";
                str+=value.getId(); str+=" ";
                str+=value.getMid(); str+=" ";
                LocalDateTime localDateTime = value.getDate();
                str+=localDateTime.getYear(); str+=" ";
                str+=localDateTime.getMonthValue(); str+=" ";
                str+=localDateTime.getDayOfMonth(); str+=" ";
                str+=localDateTime.getHour(); str+=" ";
                str+=localDateTime.getMinute(); str+=" ";
                str+=localDateTime.getSecond(); str+="\n";
                writer_orderfile.write(str);
                for(int i=0;i<orderItems.size();i++){
                    OrderItem orderItem = orderItems.get(i);
                    str="";
                    str+=orderItem.getOid(); str+=" ";
                    str+=orderItem.getCode(); str+=" ";
                    str+=orderItem.getQuantity(); str+="\n";
                    writer_orderitemfile.write(str);
                }
            }

            writer_orderfile.close();
            writer_orderitemfile.close();
        } catch(IOException e){
            System.out.println("파일쓰기에 실패했습니다!!!");
        }
        System.out.println("주문내역을 파일에 정상적으로 저장했습니다.");
        System.out.println("=======================================");
    }

    @Override
    public Order save(Order order) {
        Long oid = ++sequence;
        List<OrderItem> orderItems = order.getOrderItems();
        for(int i=0;i<orderItems.size();i++){
            orderItems.get(i).setOid(oid);
        }
        order.setOrderItems(orderItems);
        order.setId(oid);
        store.put(order.getId(), order);
        return order;
    }

    @Override
    public Optional<Order> findById(Long id) {
        return store.values().stream()
                .filter(order-> order.getId().equals(id))
                .findAny();
    }

    @Override
    public List<Order> findAll() {
        return new ArrayList<>(store.values());
    }

    @Override
    public void clearStore() {
        store.clear();
    }
}
