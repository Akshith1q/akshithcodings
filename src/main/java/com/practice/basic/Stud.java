package com.practice.basic;
import java.util.Scanner;
class Student
{
    String name;
    int rollno;
    String branch;
    String section;
    Student(String n,int x,String b,String sec)
    {
        name=n;
        rollno=x;
        branch=b;
        section=sec;
    }
    void display()
    {
        System.out.println("Name: "+name);
        System.out.println("Rollno: "+rollno);
        System.out.println("Branch: "+branch);
        System.out.println("Section: "+section);
    }
}
public class Stud
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Name,rollno,branch,section:");
        String N=sc.next();
        int a=sc.nextInt();
        String B=sc.next();
        String se=sc.next();
        Student s1=new Student(N,a,B,se);
        s1.display();

    }
}