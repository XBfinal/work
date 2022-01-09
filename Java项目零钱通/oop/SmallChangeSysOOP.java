package com.project.money.oop;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
public class SmallChangeSysOOP {
    private  double in_money=0;//当前流动的钱
    private double balance=0;//余额
    private String detailed="------------零钱通明细--------------";
    private Date date = null;
    //可以用于日期格式化的
    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm");

    public void menu(){//菜单
        boolean loop=true;
        Scanner scanner = new Scanner(System.in);
        while(loop){//循环展示菜单
            System.out.println("\n============oop零钱通菜单==============");
            System.out.println("\t\t1 零钱通明细");
            System.out.println("\t\t2 收益入账");
            System.out.println("\t\t3 消费");
            System.out.println("\t\t4 退" + "\t" + "出");
            System.out.print("请选择1-4:");int key= scanner.nextInt();//选择；
            switch (key){
                case 1:detailed_();break;
                case 2:input();break;
                case 3:output();break;
                case 4:System.out.println("\t\t程序已经退出");loop=false;break;
            }

        }
    }
    //1 零钱通明细
    public void detailed_(){
        System.out.println(detailed);
    }
    //2 收益入账"
    public void input(){//收益入账
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入金额：");
        this.in_money=scanner.nextDouble();

        while(in_money<0){
            System.out.println("======输入有误======");
            System.out.println("是否重新输入？Y（是）或 N（否） ");//可能点错了不是输入
            String in=scanner.next();//是否重新输入
            if(in.equals("n")||in.equals("N")){
                System.out.println("返回主页面中....");
                /*****************************************/
                try {
                    Thread.sleep( 1000 );//暂停1秒提升用户感受
                } catch (Exception e){}
                /*******************************************/
                return;//退出输入
            }

                System.out.println("请输入金额：");
                this.in_money=scanner.nextDouble();
        }
        this.balance+=this.in_money;
        String beizhu="";
        date = new Date();
        System.out.println("请输入备注：");
        beizhu=scanner.next();
        this.detailed+="\n收益入帐\t+" + this.in_money + "\t" + sdf.format(date) +
                "\t余额：" + this.balance+ "  备注：" +beizhu;
    }
    //3消费
    public void output(){
        System.out.println("请输入金额：");
        Scanner scanner = new Scanner(System.in);
        in_money=scanner.nextDouble();
        if(balance<in_money){
            System.out.println("余额不足，请充值");
            return;
        }
        while(in_money<0){
            System.out.println("输入错误，请重输");
            in_money=scanner.nextDouble();
            if(balance<in_money){
                System.out.println("余额不足，请充值");
                return;
            }
        }
        this.balance-=in_money;
        System.out.println("请输入备注：");
        String beizhu=scanner.next();
        this.detailed+="\n余额支出\t-" + this.in_money + "\t" + sdf.format(date) +
                "\t余额：" + this.balance+ "  备注：" +beizhu;

    }


}
