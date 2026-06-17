//program to add 2 polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node *createnode(int coeff,int exp)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->expo=exp;
    newnode->next=NULL;
    return newnode;
}
struct node *addterm(struct node *start,int coeff,int expo)
{
    struct node *newnode=createnode(coeff,expo);
    if (start==NULL||start->expo<expo) 
    {
        newnode->next=start;
        return newnode;
    }
    struct node *current=start;
    while (current->next!=NULL&&current->next->expo>=expo) 
    {
        if(current->next->expo==expo)
        {
            current->next->coeff+=coeff;
            free(newnode);
            return start;
        }
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;
    return start;
}
struct node *addpoly(struct node *poly1,struct node *poly2)
{
    struct node *result=NULL;
    while(poly1!=NULL)
    {
        result=addterm(result,poly1->coeff,poly1->expo);
        poly1=poly1->next;
    }
    while(poly2!=NULL)
    {
        result=addterm(result,poly2->coeff,poly2->expo);
        poly2=poly2->next;
    }
    return result;
}
void display(struct node *start)
{
    if (start==NULL) 
    {
        printf("Polynomial is empty.\n");
        return;
    }
    struct node *temp=start;
    while (temp!=NULL) 
    {
        if (temp->expo==0)
            printf("%d ",temp->coeff);
        else
            printf("%dx^%d ",temp->coeff,temp->expo);
        temp=temp->next;
    }
    printf("\n");
}
void main()
{
    struct node *poly1=NULL,*poly2=NULL,*result=NULL;
    int coeff,expo,choice;
    printf("1. Add term to polynomial 1\n2. Add term to polynomial 2\n3. Display polynomial 1\n4. Display polynomial 2\n5. Add  both polynomials and Display result\n6. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) 
        {
            case 1: printf("Enter coefficient and exponent: ");
                    scanf("%d %d",&coeff,&expo);
                    poly1=addterm(poly1,coeff,expo);
                    break;
            case 2: printf("Enter coefficient and exponent: ");
                    scanf("%d %d",&coeff,&expo);
                    poly2=addterm(poly2,coeff,expo);
                    break;
            case 3: printf("Polynomial 1: ");
                    display(poly1);
                    break;
            case 4: printf("Polynomial 2: ");
                    display(poly2);
                    break;
            case 5: result=addpoly(poly1,poly2);
                    printf("Resultant Polynomial: ");
                    display(result);
                    break;
            case 6: exit(0);
                    break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!=6);
}