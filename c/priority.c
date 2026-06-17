//priority queue 
#include<Stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    int pri;
    struct node *next;
}*start=NULL;
struct node *create()
{
    int n,p;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data and priority\n");
    scanf("%d%d",&n,&p);
    newnode->num=n;
    newnode->pri=p;
    newnode->next=NULL;
    return newnode;
}
struct node *enqueue()
{
    struct node *newnode,*temp;
    newnode=create();
    if(start==NULL||start->pri<newnode->pri) 
    {
        newnode->next=start;
        start=newnode;
    }
    else 
    {
        temp=start;
        while(temp->next != NULL && temp->next->pri >= newnode->pri)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return start;
}
struct node *dequeue()
{
    struct node *temp = start, *prev = NULL;
    if (start == NULL)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
        start = NULL;
    else
        prev->next = NULL;
    printf("Dequeued element: %d with priority %d\n", temp->num, temp->pri);
    free(temp);
    return start;
}
void display()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    temp=start;
    printf("Priority Queue:\n");
    while(temp!=NULL)
    {
        printf("Data: %d, Priority: %d\n",temp->num,temp->pri);
        temp=temp->next;
    }
}
void main()
{
    int ch;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start=enqueue();
                    break;
            case 2: start=dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }while(ch!=4);
}