package com.example.springmidterm.domain;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class Item {
    private String code;
    private String itemName;
    private int price;
    private int quantity;
    private List<ItemDate> itemDates;

    public Item(String code, String itemName, int price, int quantity, List<ItemDate> itemDates) {
        this.code = code;
        this.itemName = itemName;
        this.price = price;
        this.quantity = quantity;
        this.itemDates = itemDates;
    }


    public String getCode() {
        return code;
    }

    public String getItemName() {
        return itemName;
    }

    public int getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity;
    }

    public List<ItemDate> getItemDates() {
        return itemDates;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void setItemName(String itemName) {
        this.itemName = itemName;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public void setItemDates(List<ItemDate> itemDates) {
        this.itemDates = itemDates;
    }

    @Override
    public String toString() {
        String dateinfo = "";
        for(int i=0;i<itemDates.size();i++){
            LocalDateTime date = itemDates.get(i).getDate();
            dateinfo+=date.getYear(); dateinfo+=" ";
            dateinfo+=date.getMonthValue(); dateinfo+=" ";
            dateinfo+=date.getDayOfMonth(); dateinfo+=" ";
            dateinfo+=itemDates.get(i).getQuantity(); dateinfo+=" ";
            dateinfo+=itemDates.get(i).getMid(); dateinfo+="\n";
        }
        String basicinfo = "제품코드 : " + code+" / 제품이름 : "+itemName+" / 제품가격 : "+Integer.toString(price)+
                " / 제품수량 : "+ Integer.toString(quantity)+"\n";
        return basicinfo;
    }
}