package com.practice.basic;
import java.util.Scanner;
public class Pattern
{
    public static void main(String args[])
    {
        int n,i,j;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the height of pyramid:");
        n=sc.nextInt();
        for(i=0;i<n;i++)
        {
            for(j=n-i;j>1;j--)
            {
                System.out.print(" ");
            }
            for(j=0;j<=i;j++)
            {
                System.out.print("* ");
            }
            System.out.print("\n");
        }
    }
}
