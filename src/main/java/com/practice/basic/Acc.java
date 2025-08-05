package com.practice.basic;

class Account
{
    String name;
    int acno;
    float balance;
    public void setData(String n,int x,float y)
    {
        name=n;
        acno=x;
        balance=y;
    }
    public float deposit(int x,float a)
    {
        if(acno==x)
        {
            balance+=a;
            System.out.println("New balance is: "+balance);
            return balance;
        }
        else
            System.out.println("Invalid acct number");
        return balance;
    }
    public float withdraw(int x,float b)
    {
        if(acno==x)
        {
            if(balance<x)
            {
                System.out.println("Insufficient balance");
                return balance;
            }
            else
            {
                balance-=b;
                System.out.println("New balance is: "+balance);
                return balance;
            }
        }
        else
            System.out.println("Invalid acct number");
        return balance;
    }
    public float checkBal(int x)
    {
        System.out.println("Balance is: "+balance);
        return balance;
    }
    void display()
    {
        System.out.println("Name is: "+name);
        System.out.println("Account number is: "+acno);
        System.out.println("Balance is: "+balance);
    }
}
class Acc
{
    public static void main(String args[])
    {
        Account a1=new Account();
        a1.setData("Akshith",14532,230008.98f);
        a1.deposit(14532,3002.02f);
        a1.withdraw(14532,2000.1f);
        a1.checkBal(14532);
        a1.display();
    }
}