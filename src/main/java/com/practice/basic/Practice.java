package com.practice.basic;
import java.util.Scanner;
public class Practice
{
    public static void main(String[] args)
    {
        int a,b,c,d,e;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter 2 numbers\n");
        a=sc.nextInt();
        b=sc.nextInt();
        c=a+b;
        d=a-b;
        System.out.println("Sum is: "+c);
        System.out.println("Difference is: "+d);
    }
}