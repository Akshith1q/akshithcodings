package com.practice.basic;
import java.util.Scanner;
class Rect
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        RectCal r1=new RectCal();
        r1.set(5.4f,6.2f);
        r1.display();
        System.out.println("Perimeter is "+r1.perimeter());
        System.out.println("Area is "+r1.area());
        RectCal r2=new RectCal();
        float x1=sc.nextFloat();
        float x2=sc.nextFloat();
        r2.set(x1,x2);
        r2.display();
        System.out.println("Perimeter is "+r2.perimeter());
        System.out.println("Perimeter is "+r2.area());
        RectCal r3=r2;
        r3.display();
        System.out.println("Perimeter is "+r3.perimeter());
        System.out.println("Perimeter is "+r3.area());
    }
}
class RectCal
{
    private float l,w;
    public void set(float d1,float d2)
    {
        l=d1;
        w=d2;
    }
    public float perimeter()
    {
        float per=2*(l+w);
        return per;
    }
    public float area()
    {
        float ar=l*w;
        return ar;
    }
    public void display()
    {
        System.out.print("Rectance dimensions are:"+l);
        System.out.println(" "+w);
    }
}