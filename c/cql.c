//circular queue using linked list implementation in C
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void Enqueue(int value);
void Dequeue();
void Display();
void main()
{
    int ch, value;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value); 
                break;
            case 2: 
                Dequeue(); 
                break;
            case 3: 
                Display(); 
                break;
            case 4: 
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    } while(ch!=4);
}
void Enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if(front==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    rear->next=front;
}
void Dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp=front;
    if(front==rear)
        front=rear=NULL;
    else
    {
        front=front->next;
        rear->next=front;
    }
    printf("Deleted element is %d\n",temp->data);
    free(temp);
}
void Display()
{
    if(front==NULL)
    {
        printf("queue is empty\n");
        return;
    }
    struct node *temp=front;
    while(temp->next!=front)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n", temp->data);
}