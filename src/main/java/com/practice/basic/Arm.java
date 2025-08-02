package com.practice.basic;
import java.util.Scanner;
class Arm
{
    public static void main(String args[])
    {
        int s=0,r,n;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number:");
        n=sc.nextInt();
        int temp=n;
        while(n>0)
        {
            r=n%10;
            s=s+(r*r*r);
            n=n/10;
        }
        if(s==temp)
            System.out.println("Armstrong number");
        else
            System.out.println("Not an Armstrong number");
    }
}