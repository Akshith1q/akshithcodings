package com.practice.basic;
import java.util.Scanner;
class Adding
{
    int a,b;
    float c,d,e;
    double f,g,h,i;
    int add(int a,int b)
    {
        int res=a+b;
        System.out.println("Sum is: "+res);
        return res;
    }
    float add(float c,float d,float e)
    {
        float sum=c+d+e;
        System.out.println("Sum is: "+sum);
        return sum;
    }
    double add(double f,double g,double h,double i)
    {
        double val=f+g+h+i;
        System.out.println("Sum is: "+val);
        return val;
    }
}
public class Add
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int A=sc.nextInt();
        int B=sc.nextInt();
        float C=sc.nextFloat();
        float D=sc.nextFloat();
        float E=sc.nextFloat();
        double F=sc.nextDouble();
        double G=sc.nextDouble();
        double H=sc.nextDouble();
        double I=sc.nextDouble();
        Adding a1=new Adding();
        a1.add(A,B);
        a1.add(C,D,E);
        a1.add(F,G,H,I);
    }
}
