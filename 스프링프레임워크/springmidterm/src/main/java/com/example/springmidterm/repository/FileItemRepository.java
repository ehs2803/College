package com.example.springmidterm.repository;

import com.example.springmidterm.domain.Item;
import com.example.springmidterm.domain.ItemDate;
import com.example.springmidterm.domain.Member;
import com.example.springmidterm.domain.Role;
import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.lang.Nullable;

import java.io.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.*;

public class FileItemRepository implements ItemRepository, InitializingBean, DisposableBean {
    private static File itemfile = new File("item.txt");
    private static File itemdatefile = new File("itemdate.txt");
    private static final Map<String, Item> store = new HashMap<>();

    @Override
    public void afterPropertiesSet() throws Exception {
        if(itemfile.exists() && itemdatefile.exists()) {
            BufferedReader inFile_itemfile = new BufferedReader(new FileReader(itemfile));
            BufferedReader inFile_itemdatefile = new BufferedReader(new FileReader(itemdatefile));
            String sLine = null;
            while( (sLine = inFile_itemfile.readLine()) != null ) {
                String [] splitstr = sLine.split(" ");
                Item item = new Item(splitstr[0], splitstr[1],
                        Integer.parseInt(splitstr[2]), Integer.parseInt(splitstr[3]), new ArrayList<ItemDate>());
                store.put(splitstr[0], item);
            }
            while( (sLine = inFile_itemdatefile.readLine()) != null ) {
                String [] splitstr = sLine.split(" ");
                LocalDateTime localDateTime = LocalDateTime.of(Integer.parseInt(splitstr[2]),
                        Integer.parseInt(splitstr[3]),Integer.parseInt(splitstr[4]),
                        Integer.parseInt(splitstr[5]),Integer.parseInt(splitstr[6]),
                        Integer.parseInt(splitstr[7]));

                ItemDate itemDate = new ItemDate(splitstr[0], Long.parseLong(splitstr[1]),
                        localDateTime, Integer.parseInt(splitstr[8]));

                Item item = store.get(splitstr[0]);
                List<ItemDate> itemDates = item.getItemDates();
                itemDates.add(itemDate);
                item.setItemDates(itemDates);
                store.put(splitstr[0], item);
            }

            inFile_itemfile.close();
            inFile_itemdatefile.close();
        }
    }

    @Override
    public void destroy() throws Exception {
        try{
            BufferedWriter writer_itemfile = new BufferedWriter(new FileWriter(itemfile));
            BufferedWriter writer_itemdatefile = new BufferedWriter(new FileWriter(itemdatefile));
            for (Map.Entry<String, Item> entry : store.entrySet()) {
                String key = entry.getKey();
                Item value = entry.getValue();
                List<ItemDate> itemDates = value.getItemDates();
                String str = "";
                str+=value.getCode(); str+=" ";
                str+=value.getItemName(); str+=" ";
                str+=value.getPrice(); str+=" ";
                str+=value.getQuantity(); str+="\n";
                writer_itemfile.write(str);
                for(int i=0;i<itemDates.size();i++){
                    ItemDate itemDate = itemDates.get(i);
                    str="";
                    str+=itemDate.getCode(); str+=" ";
                    str+=itemDate.getMid(); str+=" ";
                    LocalDateTime localDateTime = itemDate.getDate();
                    str+=localDateTime.getYear(); str+=" ";
                    str+=localDateTime.getMonthValue(); str+=" ";
                    str+=localDateTime.getDayOfMonth(); str+=" ";
                    str+=localDateTime.getHour(); str+=" ";
                    str+=localDateTime.getMinute(); str+=" ";
                    str+=localDateTime.getSecond(); str+=" ";
                    str+=itemDate.getQuantity(); str+="\n";
                    writer_itemdatefile.write(str);
                }
            }
            writer_itemfile.close();
            writer_itemdatefile.close();
        } catch(IOException e){
            System.out.println("파일쓰기에 실패했습니다!!!");
        }
        System.out.println("상품 재고를 파일에 정상적으로 저장했습니다.");
        System.out.println("=======================================");
    }

    @Override
    public Item save(Item item) {
        store.put(item.getCode(), item);
        return item;
    }

    @Override
    public Optional<Item> findBycode(String code) {
        return store.values().stream()
                .filter(item -> item.getCode().equals(code))
                .findAny();
    }

    @Override
    public List<Item> findAll() {
        return new ArrayList<>(store.values());
    }

    @Override
    public Item update(String code, Item updateParam) {
        Item updateItem = findBycode(code).get();
        updateItem.setItemName(updateParam.getItemName());
        updateItem.setPrice(updateParam.getPrice());
        store.put(code, updateItem);
        return updateItem;
    }

    @Override
    public Item updateQuantity(String code, int quantity, Long mid, LocalDateTime localDateTime){
        Item increaseitem = findBycode(code).get();
        int originalquantity = increaseitem.getQuantity();
        increaseitem.setQuantity(originalquantity+quantity);
        List<ItemDate> itemDates = increaseitem.getItemDates();
        ItemDate newitemdate = new ItemDate(code,mid,localDateTime, quantity);
        itemDates.add(newitemdate);
        increaseitem.setItemDates(itemDates);
        store.put(code, increaseitem);
        return increaseitem;
    }

    @Override
    public Item reduceQuantityByOrder(String code, int quantity, Long mid, LocalDateTime localDateTime){
        Item reduceitem = findBycode(code).get();
        int originalquantity = reduceitem.getQuantity();
        reduceitem.setQuantity(originalquantity-quantity);
        List<ItemDate> itemDates = reduceitem.getItemDates();
        ItemDate newitemdate = new ItemDate(code,mid,localDateTime, -quantity);
        itemDates.add(newitemdate);
        reduceitem.setItemDates(itemDates);
        store.put(code, reduceitem);
        return reduceitem;
    }

    @Override
    public void clearStore() {
        store.clear();
    }
}