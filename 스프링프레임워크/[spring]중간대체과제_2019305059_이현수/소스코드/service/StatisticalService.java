package com.example.springmidterm.service;

import com.example.springmidterm.domain.Order;
import com.example.springmidterm.domain.OrderItem;
import com.example.springmidterm.repository.ItemRepository;
import com.example.springmidterm.repository.OrderRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;
import java.util.*;

@Component
public class StatisticalService {
    private final ItemRepository itemRepository;
    private final OrderRepository orderRepository;

    @Autowired
    public StatisticalService(ItemRepository itemRepository, OrderRepository orderRepository) {
        this.itemRepository = itemRepository;
        this.orderRepository = orderRepository;
    }

    public void maxQuantityItemPerDate(){
        List<Order> orders = orderRepository.findAll();
        Map<LocalDateTime, Map<String, Integer>> quantityPerWeeks = new HashMap<>();

        // 하루 최대 판매량 제품 구하기
        for(int i=0;i<orders.size();i++){
            LocalDateTime datetime = orders.get(i).getDate();
            LocalDateTime preprocessingDatetime = LocalDateTime.of(datetime.getYear(), datetime.getMonthValue(),
                    datetime.getDayOfMonth(),0,0,0);
            if(quantityPerWeeks.containsKey(preprocessingDatetime)){
                Map<String, Integer> temp = quantityPerWeeks.get(preprocessingDatetime);
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempquantity = temp.get(code);
                        tempquantity+=quantity;
                        temp.put(code, tempquantity);
                    }
                    else{
                        temp.put(code, quantity);
                    }
                }
                quantityPerWeeks.put(preprocessingDatetime, temp);
            }
            else{
                Map<String, Integer> temp = new HashMap<>();
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempquantity = temp.get(code);
                        tempquantity+=quantity;
                        temp.put(code, tempquantity);
                    }
                    else{
                        temp.put(code, quantity);
                    }
                }
                quantityPerWeeks.put(preprocessingDatetime, temp);
            }
        }
        // 날짜기준 오름차순 정렬
        Object[] mapkey = quantityPerWeeks.keySet().toArray();
        Arrays.sort(mapkey);

        // 날짜별 최대 판매량 재품 정렬 출력
        for(Map.Entry<LocalDateTime, Map<String, Integer>> entry : quantityPerWeeks.entrySet()){
            LocalDateTime key = entry.getKey();
            Map<String, Integer> values = entry.getValue();
            List<Map.Entry<String, Integer>> list_entries = new ArrayList<Map.Entry<String, Integer>>(values.entrySet());

            // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
            Collections.sort(list_entries, new Comparator<Map.Entry<String, Integer>>() {
                // compare로 값을 비교
                public int compare(Map.Entry<String, Integer> obj1, Map.Entry<String, Integer> obj2)
                {
                    // 내림 차순으로 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            System.out.print("["+key.getYear()+"/"+key.getMonthValue()+"/"
                    +key.getDayOfMonth()+"의 최대판매량 제품] ");
            System.out.println("코드 : "+list_entries.get(0).getKey()
                    + " / 제품이름 : "+itemRepository.findBycode(list_entries.get(0).getKey()).get().getItemName()
                + " / 판매수량 : " + list_entries.get(0).getValue());
        }
    }

    public void maxQuantityItemPerWeek(){
        List<Order> orders = orderRepository.findAll();
        Map<LocalDateTime, Map<String, Integer>> quantityPerDates = new HashMap<>();

        // 하루 최대 판매량 제품 구하기
        for(int i=0;i<orders.size();i++){
            LocalDateTime datetime = orders.get(i).getDate();
            LocalDateTime preprocessingDatetime= LocalDateTime.of(datetime.getYear(), datetime.getMonthValue(),
                    datetime.getDayOfMonth(),0,0,0);
            if(datetime.getDayOfWeek().getValue()!=1){
                int getdayofweek = datetime.getDayOfWeek().getValue();
                preprocessingDatetime = preprocessingDatetime.minusDays(getdayofweek-1);
            }

            if(quantityPerDates.containsKey(preprocessingDatetime)){
                Map<String, Integer> temp = quantityPerDates.get(preprocessingDatetime);
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempquantity = temp.get(code);
                        tempquantity+=quantity;
                        temp.put(code, tempquantity);
                    }
                    else{
                        temp.put(code, quantity);
                    }
                }
                quantityPerDates.put(preprocessingDatetime, temp);
            }
            else{
                Map<String, Integer> temp = new HashMap<>();
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempquantity = temp.get(code);
                        tempquantity+=quantity;
                        temp.put(code, tempquantity);
                    }
                    else{
                        temp.put(code, quantity);
                    }
                }
                quantityPerDates.put(preprocessingDatetime, temp);
            }
        }
        // 날짜기준 오름차순 정렬
        Object[] mapkey = quantityPerDates.keySet().toArray();
        Arrays.sort(mapkey);

        // 날짜별 최대 판매량 재품 정렬 출력
        for(Map.Entry<LocalDateTime, Map<String, Integer>> entry : quantityPerDates.entrySet()){
            LocalDateTime key = entry.getKey();
            Map<String, Integer> values = entry.getValue();
            List<Map.Entry<String, Integer>> list_entries = new ArrayList<Map.Entry<String, Integer>>(values.entrySet());

            // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
            Collections.sort(list_entries, new Comparator<Map.Entry<String, Integer>>() {
                // compare로 값을 비교
                public int compare(Map.Entry<String, Integer> obj1, Map.Entry<String, Integer> obj2)
                {
                    // 내림 차순으로 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            LocalDateTime plusdatetime = LocalDateTime.of(key.getYear(), key.getMonthValue(), key.getDayOfMonth(),
                    0,0,0);
            plusdatetime = plusdatetime.plusDays(6);
            System.out.print("["+key.getYear()+"/"+key.getMonthValue()+"/"
                    +key.getDayOfMonth()+"~"+plusdatetime.getYear()+"/"+
                    plusdatetime.getMonthValue()+"/"+plusdatetime.getDayOfMonth()+"의 최대판매량 제품] ");
            System.out.println("코드 : "+list_entries.get(0).getKey()
                    + " / 제품이름 : "+itemRepository.findBycode(list_entries.get(0).getKey()).get().getItemName()
                    + " / 판매수량 : " + list_entries.get(0).getValue());
        }
    }

    public void maxQuantityItemPerMonth(){
        List<Order> orders = orderRepository.findAll();
        Map<LocalDateTime, Map<String, Integer>> quantityPerMonths = new HashMap<>();

        // 하루 최대 판매량 제품 구하기
        for(int i=0;i<orders.size();i++){
            LocalDateTime datetime = orders.get(i).getDate();
            LocalDateTime preprocessingDatetime = LocalDateTime.of(datetime.getYear(), datetime.getMonthValue(),
                    1,0,0,0);
            if(quantityPerMonths.containsKey(preprocessingDatetime)){
                Map<String, Integer> temp = quantityPerMonths.get(preprocessingDatetime);
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempquantity = temp.get(code);
                        tempquantity+=quantity;
                        temp.put(code, tempquantity);
                    }
                    else{
                        temp.put(code, quantity);
                    }
                }
                quantityPerMonths.put(preprocessingDatetime, temp);
            }
            else{
                Map<String, Integer> temp = new HashMap<>();
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempquantity = temp.get(code);
                        tempquantity+=quantity;
                        temp.put(code, tempquantity);
                    }
                    else{
                        temp.put(code, quantity);
                    }
                }
                quantityPerMonths.put(preprocessingDatetime, temp);
            }
        }
        // 날짜기준 오름차순 정렬
        Object[] mapkey = quantityPerMonths.keySet().toArray();
        Arrays.sort(mapkey);

        // 날짜별 최대 판매량 재품 정렬 출력
        for(Map.Entry<LocalDateTime, Map<String, Integer>> entry : quantityPerMonths.entrySet()){
            LocalDateTime key = entry.getKey();
            Map<String, Integer> values = entry.getValue();
            List<Map.Entry<String, Integer>> list_entries = new ArrayList<Map.Entry<String, Integer>>(values.entrySet());

            // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
            Collections.sort(list_entries, new Comparator<Map.Entry<String, Integer>>() {
                // compare로 값을 비교
                public int compare(Map.Entry<String, Integer> obj1, Map.Entry<String, Integer> obj2)
                {
                    // 내림 차순으로 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            System.out.print("["+key.getYear()+"/"+key.getMonthValue()
                    +"의 최대판매량 제품] ");
            System.out.println("코드 : "+list_entries.get(0).getKey()
                    + " / 제품이름 : "+itemRepository.findBycode(list_entries.get(0).getKey()).get().getItemName()
                    + " / 판매수량 : " + list_entries.get(0).getValue());
        }
    }

    public void maxPriceItemPerDate(){
        List<Order> orders = orderRepository.findAll();
        Map<LocalDateTime, Map<String, Integer>> pricePerDates = new HashMap<>();

        // 하루 최대 판매량 제품 구하기
        for(int i=0;i<orders.size();i++){
            LocalDateTime datetime = orders.get(i).getDate();
            LocalDateTime preprocessingDatetime = LocalDateTime.of(datetime.getYear(), datetime.getMonthValue(),
                    datetime.getDayOfMonth(),0,0,0);
            if(pricePerDates.containsKey(preprocessingDatetime)){
                Map<String, Integer> temp = pricePerDates.get(preprocessingDatetime);
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempprice = temp.get(code);
                        temp.put(code, tempprice+quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                    else{
                        temp.put(code, quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                }
                pricePerDates.put(preprocessingDatetime, temp);
            }
            else{
                Map<String, Integer> temp = new HashMap<>();
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempprice = temp.get(code);
                        temp.put(code, tempprice+quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                    else{
                        temp.put(code, quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                }
                pricePerDates.put(preprocessingDatetime, temp);
            }
        }
        // 날짜기준 오름차순 정렬
        Object[] mapkey = pricePerDates.keySet().toArray();
        Arrays.sort(mapkey);

        // 날짜별 최대 판매량 재품 정렬 출력
        for(Map.Entry<LocalDateTime, Map<String, Integer>> entry : pricePerDates.entrySet()){
            LocalDateTime key = entry.getKey();
            Map<String, Integer> values = entry.getValue();
            List<Map.Entry<String, Integer>> list_entries = new ArrayList<Map.Entry<String, Integer>>(values.entrySet());

            // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
            Collections.sort(list_entries, new Comparator<Map.Entry<String, Integer>>() {
                // compare로 값을 비교
                public int compare(Map.Entry<String, Integer> obj1, Map.Entry<String, Integer> obj2)
                {
                    // 내림 차순으로 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            System.out.print("["+key.getYear()+"/"+key.getMonthValue()+"/"
                    +key.getDayOfMonth()+"의 최대판매가격 제품] ");
            System.out.println("코드 : "+list_entries.get(0).getKey()
                    + " / 제품이름 : "+itemRepository.findBycode(list_entries.get(0).getKey()).get().getItemName()
                    + " / 판매액 : " + list_entries.get(0).getValue());
        }
    }

    public void maxPriceItemPerWeek(){
        List<Order> orders = orderRepository.findAll();
        Map<LocalDateTime, Map<String, Integer>> pricePerMonths = new HashMap<>();

        // 하루 최대 판매량 제품 구하기
        for(int i=0;i<orders.size();i++){
            LocalDateTime datetime = orders.get(i).getDate();
            LocalDateTime preprocessingDatetime= LocalDateTime.of(datetime.getYear(), datetime.getMonthValue(),
                    datetime.getDayOfMonth(),0,0,0);
            if(datetime.getDayOfWeek().getValue()!=1){
                int getdayofweek = datetime.getDayOfWeek().getValue();
                preprocessingDatetime = preprocessingDatetime.minusDays(getdayofweek-1);
            }
            if(pricePerMonths.containsKey(preprocessingDatetime)){
                Map<String, Integer> temp = pricePerMonths.get(preprocessingDatetime);
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempprice = temp.get(code);
                        temp.put(code, tempprice+quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                    else{
                        temp.put(code, quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                }
                pricePerMonths.put(preprocessingDatetime, temp);
            }
            else{
                Map<String, Integer> temp = new HashMap<>();
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempprice = temp.get(code);
                        temp.put(code, tempprice+quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                    else{
                        temp.put(code, quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                }
                pricePerMonths.put(preprocessingDatetime, temp);
            }
        }
        // 날짜기준 오름차순 정렬
        Object[] mapkey = pricePerMonths.keySet().toArray();
        Arrays.sort(mapkey);

        // 날짜별 최대 판매량 재품 정렬 출력
        for(Map.Entry<LocalDateTime, Map<String, Integer>> entry : pricePerMonths.entrySet()){
            LocalDateTime key = entry.getKey();
            Map<String, Integer> values = entry.getValue();
            List<Map.Entry<String, Integer>> list_entries = new ArrayList<Map.Entry<String, Integer>>(values.entrySet());

            // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
            Collections.sort(list_entries, new Comparator<Map.Entry<String, Integer>>() {
                // compare로 값을 비교
                public int compare(Map.Entry<String, Integer> obj1, Map.Entry<String, Integer> obj2)
                {
                    // 내림 차순으로 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            LocalDateTime plusdatetime = LocalDateTime.of(key.getYear(), key.getMonthValue(), key.getDayOfMonth(),
                    0,0,0);
            plusdatetime = plusdatetime.plusDays(6);
            System.out.print("["+key.getYear()+"/"+key.getMonthValue()+"/"
                    +key.getDayOfMonth()+"~"+plusdatetime.getYear()+"/"+
                    plusdatetime.getMonthValue()+"/"+plusdatetime.getDayOfMonth()+"의 최대판매가격 제품] ");
            System.out.println("코드 : "+list_entries.get(0).getKey()
                    + " / 제품이름 : "+itemRepository.findBycode(list_entries.get(0).getKey()).get().getItemName()
                    + " / 판매액 : " + list_entries.get(0).getValue());
        }
    }

    public void maxPriceItemPerMonth(){
        List<Order> orders = orderRepository.findAll();
        Map<LocalDateTime, Map<String, Integer>> pricePerMonths = new HashMap<>();

        // 하루 최대 판매량 제품 구하기
        for(int i=0;i<orders.size();i++){
            LocalDateTime datetime = orders.get(i).getDate();
            LocalDateTime preprocessingDatetime = LocalDateTime.of(datetime.getYear(), datetime.getMonthValue(),
                    1,0,0,0);
            if(pricePerMonths.containsKey(preprocessingDatetime)){
                Map<String, Integer> temp = pricePerMonths.get(preprocessingDatetime);
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempprice = temp.get(code);
                        temp.put(code, tempprice+quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                    else{
                        temp.put(code, quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                }
                pricePerMonths.put(preprocessingDatetime, temp);
            }
            else{
                Map<String, Integer> temp = new HashMap<>();
                List<OrderItem> orderItems = orders.get(i).getOrderItems();
                for(int j=0;j<orderItems.size();j++){
                    String code = orderItems.get(j).getCode();
                    int quantity = orderItems.get(j).getQuantity();
                    if(temp.containsKey(code)){
                        int tempprice = temp.get(code);
                        temp.put(code, tempprice+quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                    else{
                        temp.put(code, quantity*itemRepository.findBycode(code).get().getPrice());
                    }
                }
                pricePerMonths.put(preprocessingDatetime, temp);
            }
        }
        // 날짜기준 오름차순 정렬
        Object[] mapkey = pricePerMonths.keySet().toArray();
        Arrays.sort(mapkey);

        // 날짜별 최대 판매량 재품 정렬 출력
        for(Map.Entry<LocalDateTime, Map<String, Integer>> entry : pricePerMonths.entrySet()){
            LocalDateTime key = entry.getKey();
            Map<String, Integer> values = entry.getValue();
            List<Map.Entry<String, Integer>> list_entries = new ArrayList<Map.Entry<String, Integer>>(values.entrySet());

            // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
            Collections.sort(list_entries, new Comparator<Map.Entry<String, Integer>>() {
                // compare로 값을 비교
                public int compare(Map.Entry<String, Integer> obj1, Map.Entry<String, Integer> obj2)
                {
                    // 내림 차순으로 정렬
                    return obj2.getValue().compareTo(obj1.getValue());
                }
            });
            System.out.print("["+key.getYear()+"/"+key.getMonthValue()+
                   "의 최대판매가격 제품] ");
            System.out.println("코드 : "+list_entries.get(0).getKey()
                    + " / 제품이름 : "+itemRepository.findBycode(list_entries.get(0).getKey()).get().getItemName()
                    + " / 판매액 : " + list_entries.get(0).getValue());
        }
    }
}
