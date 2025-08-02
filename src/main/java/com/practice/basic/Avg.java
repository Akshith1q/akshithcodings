package com.practice.basic;
import java.util.Scanner;
class Avg
{
    public static void main(String args[])
    {
        int a,b,c,d;
        float avg;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter 4 marks:");
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        d=sc.nextInt();
        avg=(a+b+c+d)/4.0f;
        System.out.println("average is:"+avg);
        if(avg>=90)
            System.out.println("Grade O");
        else if(avg>=80&&avg<90)
            System.out.println("Grade A");
        else if(avg>=70&&avg<80)
            System.out.println("Grade B");
        else if(avg>=60&&avg<70)
            System.out.println("Grade C");
        else if(avg>=50&&avg<60)
            System.out.println("Grade D");
        else
            System.out.println("Failed");
    }
}