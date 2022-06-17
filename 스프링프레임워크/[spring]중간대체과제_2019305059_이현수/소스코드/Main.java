package com.example.springmidterm;

import com.example.springmidterm.domain.*;
import com.example.springmidterm.service.InventoryService;
import com.example.springmidterm.service.MemberService;
import com.example.springmidterm.service.OrderService;
import com.example.springmidterm.service.StatisticalService;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import java.io.IOException;
import java.time.LocalDateTime;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(JavaConfig.class);
        MemberService memSvc = (MemberService)ctx.getBean("memberService");
        InventoryService intSvc = (InventoryService)ctx.getBean("inventoryService");
        OrderService orderSvc = (OrderService)ctx.getBean("orderService");
        StatisticalService stSvc = (StatisticalService)ctx.getBean("statisticalService");

        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("=======================================");
            System.out.println("1. 로그인");
            System.out.println("2. 회원가입");
            System.out.println("3. 종료");
            System.out.println("=======================================");
            int menu = sc.nextInt();
            System.out.println("=======================================");
            if(menu==1){
                boolean logincheck = true;
                System.out.println("아이디를 입력하세요: ");
                String email = sc.next();
                System.out.println("비밀번호를 입력하세요: ");
                String password = sc.next();
                System.out.println("=======================================");
                Member loginmember = null;
                Optional<Member> checkmember = memSvc.findByEmail(email);
                if(!checkmember.isPresent()){
                    System.out.println("이메일 아이디 혹은 비밀번호를 확인하세요!");
                    logincheck=false;
                }
                else{
                    loginmember = memSvc.findByEmail(email).get();
                    if(!loginmember.getPassword().equals(password)){
                        System.out.println("이메일 아이디 혹은 비밀번호를 확인하세요!");
                        logincheck=false;
                    }
                }
                if(logincheck){
                    System.out.println("로그인에 성공했습니다!!");
                    System.out.println("계정아이디 : "+ loginmember.getEmail()+" / 직책 : "+loginmember.getRole());
                    while(true){
                        System.out.println("=======================================");
                        System.out.println("1. 계산하기");
                        System.out.println("2. 재고관리");
                        System.out.println("3. 재고현황");
                        System.out.println("4. 통계보기");
                        System.out.println("5. 로그아웃");
                        System.out.println("=======================================");
                        int usermenu = sc.nextInt();
                        System.out.println("=======================================");
                        if(usermenu==1){
                            List<OrderItem> orderItems = new ArrayList<>();
                            List<Item> items = intSvc.allItem();
                            int totalPrice=0;
                            while(true){
                                for(int i=0;i<items.size();i++){
                                    System.out.println(i+1+". "+items.get(i).getItemName()
                                            +" - "+items.get(i).getPrice()+"원");
                                }
                                System.out.println("=======================================");
                                System.out.println("어떤 상품을 선택하실 겁니까? 0을 선택하면 계산이 시작됩니다.");
                                int sel = sc.nextInt();
                                System.out.println("=======================================");
                                if(sel==0) break;
                                else{
                                    System.out.println(items.get(sel-1).getItemName()+"을 몇개 살건가요?");
                                    int cnt = sc.nextInt();
                                    System.out.println("=======================================");
                                    if(orderSvc.IsvalidQuantity(items.get(sel-1).getCode(), cnt)){
                                        boolean check_buy = false;
                                        for(int i=0;i<orderItems.size();i++){
                                            if(orderItems.get(i).getCode().equals(items.get(sel-1).getCode())){
                                                check_buy = true;
                                                int alreadybuycnt = orderItems.get(i).getQuantity();
                                                orderItems.get(i).setquantity(alreadybuycnt+cnt);
                                            }
                                        }
                                        if(check_buy==false){
                                            OrderItem orderItem = new OrderItem(items.get(sel-1).getCode(), cnt);
                                            orderItems.add(orderItem);
                                        }
                                        totalPrice += cnt*items.get(sel-1).getPrice();
                                    }
                                    else{
                                        System.out.println("수량이 부족합니다.");
                                        System.out.println("=======================================");
                                    }
                                }
                            }
                            if(orderItems.size()>0){
                                System.out.println("총 "+totalPrice+"원 입니다. 결제를 하시겠습니까? [y/n]");
                                String checkbuy = sc.next();
                                System.out.println("=======================================");
                                if(checkbuy.equals("y") || checkbuy.equals("Y")){
                                    orderSvc.createOrder(loginmember.getId(), orderItems);
                                    System.out.println("계산이 완료되었습니다.");
                                    System.out.println("=======================================");
                                }
                                else{
                                    System.out.println("계산이 취소되었습니다.");
                                    System.out.println("=======================================");
                                }
                            }
                            else{
                                System.out.println("선택한 상품이 없습니다. 계산을 종료합니다.");
                                System.out.println("=======================================");
                            }
                        }
                        else if(usermenu==2){
                            System.out.println("제품 code를 입력하세요: ");
                            String code = sc.next();
                            System.out.println("=======================================");
                            if(!intSvc.validateDuplicateItem(code)){
                                System.out.println("제품 이름을 입력하세요: ");
                                String name = sc.next();
                                System.out.println("제품 가격을 입력하세요: ");
                                int price = sc.nextInt();
                                System.out.println("제품 수량을 입력하세요: ");
                                int quantity = sc.nextInt();
                                ItemDate itemDate = new ItemDate(code, loginmember.getId(),LocalDateTime.now(), quantity);
                                List<ItemDate> itemDates = new ArrayList<ItemDate>();
                                itemDates.add(itemDate);
                                Item newitem = new Item(code,name,price,quantity, itemDates);
                                intSvc.addItem(newitem);
                                System.out.println("새로운 상품이 추가되었습니다!");
                                System.out.println("=======================================");
                            }
                            else{
                                System.out.println("제품 수량을 입력하세요: ");
                                int quantity = sc.nextInt();
                                System.out.println("=======================================");
                                intSvc.updateItem(code, quantity, loginmember.getId(), LocalDateTime.now());
                                System.out.println("상품의 재고 수량이 업데이트 되었습니다.");
                                System.out.println("=======================================");
                            }
                        }
                        else if(usermenu==3){
                            List<Item> items = intSvc.allItem();
                            for(int i=0;i<items.size();i++){
                                System.out.println(items.get(i).toString());
                            }
                        }
                        else if(usermenu==4){
                            System.out.println("<일별 최대판매량 제품>");
                            stSvc.maxQuantityItemPerDate();
                            System.out.println();

                            System.out.println("<주별 최대판매량 제품>");
                            stSvc.maxQuantityItemPerWeek();
                            System.out.println();

                            System.out.println("<월별 최대판매량 제품>");
                            stSvc.maxQuantityItemPerMonth();
                            System.out.println();

                            System.out.println("<일별 최대매출액 제품>");
                            stSvc.maxPriceItemPerDate();
                            System.out.println();

                            System.out.println("<주별 최대매출액 제품>");
                            stSvc.maxPriceItemPerWeek();
                            System.out.println();

                            System.out.println("<월별 최대매출액 제품>");
                            stSvc.maxPriceItemPerMonth();
                            System.out.println();
                        }
                        else if(usermenu==5){
                            System.out.println("로그아웃 되었습니다.");
                            System.out.println("=======================================");
                            break;
                        }
                    }
                }
            }
            else if(menu==2){
                System.out.println("아이디를 입력하세요: ");
                String input_mail = sc.next();
                System.out.println("=======================================");
                if(memSvc.validateDuplicateMember(input_mail)){
                    System.out.println("이미 있는 이메일 아이디입니다!!");
                }
                else{
                    System.out.println("사용 가능한 아이디 입니다.");
                    System.out.println("비밀번호를 입력하세요: ");
                    String input_pwd = sc.next();
                    System.out.println("직책을 선택하세요!! 1. 매니저 2. 직원? ");
                    int input_role = sc.nextInt();
                    System.out.println("=======================================");
                    Member newmember;
                    if(input_role==1) newmember = new Member(input_mail, input_pwd, Role.MANAGER);
                    else newmember = new Member(input_mail,input_pwd, Role.EMPLOYEE);
                    memSvc.join(newmember);
                    System.out.println("회원가입이 완료되었습니다.");
                    System.out.println("=======================================");
                }
            }
            else{
                break;
            }
        }

        ctx.close();
    }
}
