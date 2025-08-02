package com.practice.basic;
import java.util.Scanner;
class Prime
{
    public static void main(String args[])
    {
        int m, n;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the range:");
        m=sc.nextInt();
        n=sc.nextInt();
        System.out.println("Prime numbers between "+m+" and "+n+" are:");
        for (int i=m;i<=n;i++)
        {
            if (i<2) 
                continue;
            boolean isPrime=true;
            for (int j=2;j*j<=i;j++)
            {
                if (i%j==0)
                {
                    isPrime=false;
                    break;
                }
            }
            if (isPrime)
                System.out.println(i);
        }
    }
}