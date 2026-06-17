//circular linked list implementation in C
#include <stdio.h>
#include <stdlib.h> 
struct node 
{
    int data;
    struct node *next;
}*start=NULL;
void Insert_Start()
{
    struct node *newnode;
    int n;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &n);
    newnode->data=n;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        struct node *temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=start;
        start=newnode;
    }
}
void Insert_End()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("Enter the data: ");
    scanf("%d",&n);
    newnode->data=n;
    if(start==NULL)
    { 
        start=newnode;
        newnode->next=start;
    }
    else
    {
        struct node *temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=start;
    }
}
void Insert_Anywhere()
{
    struct node *newnode, *temp=start;
    int n,pos,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&n);
    newnode->data=n;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        printf("Enter position to insert: ");
        scanf("%d",&pos);
        if(pos<1)
        {
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        if(pos==1)
        {
            Insert_Start();
            return;
        }
        else
        {
            while(temp->next!=start&&i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            if(i!=pos-1)
            {
                printf("Invalid position\n");
                return;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void Delete_Start()
{
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        struct node *temp=start;
        if(temp->next==start)
        {
            free(temp); 
            start=NULL;
        }
        else
        {
            struct node *last=start;
            while(last->next!=start)
                last=last->next;
            start=start->next;
            last->next=start;
            free(temp);
        }
    }
}
void Delete_End()
{
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        struct node *temp=start;
        if(temp->next==start)
        {
            free(temp);
            start=NULL;
        }
        else
        {
            struct node *prev=NULL;
            while(temp->next!=start)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=start;
            free(temp);
        }
    }
}
void Delete_Anywhere()
{
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    int pos,i=1;
    struct node *temp=start, *prev=NULL;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos<1)
    {
        printf("Invalid position\n");
        return;
    }
    if(pos==1)
    {
        Delete_Start();
        return;
    }
    while(i<pos&&temp->next!=start)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    if(i==pos&&temp->next!=start)
    {
        prev->next=temp->next;
        free(temp);
    }
    else
        printf("Position invalid\n");
}
void Search()
{
    int key,flag=0,i=1;
    struct node *temp=start;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter key element: ");
    scanf("%d",&key);
    while(temp->next!=start)
    {
        if(temp->data==key)
        {
            flag=1;
            break;
        }
        temp=temp->next;
        i++;
    }
    if(temp->data==key)
        flag=1;
    if(flag==1)
        printf("Element found at %d\n",i);
    else
        printf("Element not found\n");
}
void Display()
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    struct node *temp=start;
    while(temp->next!=start)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void main()
{
    int ch;
    do
    {
        printf("1. Insert_Start\n2. Insert_End\n3. Insert_Anywhere\n4. Delete_Start\n5. Delete_End\n6. Delete_Anywhere\n7. Search\n8. Display\n9. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: Insert_Start(); 
                    break;
            case 2: Insert_End(); 
                    break;
            case 3: Insert_Anywhere(); 
                    break;
            case 4: Delete_Start(); 
                    break;
            case 5: Delete_End(); 
                    break;
            case 6: Delete_Anywhere(); 
                    break;
            case 7: Search();
                    break;
            case 8: Display();
                    break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    } while(ch!=9);
}