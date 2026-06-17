#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*f=NULL,*r=NULL;
void enqueue()
{
    int n;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&n);
    newnode->data=n;
    if(f==NULL)
    {
        f=r=newnode;
        newnode->next=f;
    }
    else
    {
        r->next=newnode;
        r=newnode;
        newnode->next=f;
    }
}
void dequeue()
{
    if(f==NULL)
    {
        printf("queue is empty\n");
        return;
    }
    else
    {
        struct node *temp=f;
        printf("deleted element is %d\n",temp->data);
        f=f->next;
        r->next=f;
        free(temp);
    }
    if(f==r)
        f=r=NULL;
}
void display()
{
    struct node *temp=f;
    while(temp->next!=f)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void main()
{
    // int ch;
    // printf("main menu");
    //switch case
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    display();
}