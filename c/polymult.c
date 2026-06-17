#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *createnode(int coeff, int exp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}
struct node *insert_term(struct node *poly, int coeff, int exp)
{
    struct node *newnode = createnode(coeff, exp);
    if (poly == NULL)
        poly = newnode;
    else
    {
        struct node *temp = poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return poly;
}
struct node *polymultiplication(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL;
    for (struct node *p1 = poly1; p1 != NULL; p1 = p1->next)
    {
        for (struct node *p2 = poly2; p2 != NULL; p2 = p2->next)
        {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            result = insert_term(result, coeff, exp);
        }
    }
    return result;
}

void display(struct node *poly)
{
    if (poly == NULL)
    {
        printf("No data\n");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf("+ ");
    }
}

void main()
{
    struct node *result = NULL, *poly1 = NULL, *poly2 = NULL;
    int coeff, exp, choice;
    do
    {
        printf("\n1. Insert term in polynomial 1\n2. Insert term in polynomial 2\n3. Multiply polynomials\n4. Display polynomial 1\n5. Display polynominal 2\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter coefficient and exponent: ");
            scanf("%d %d", &coeff, &exp);
            poly1=insert_term(poly1,coeff,exp);
            break;
        case 2:
            printf("Enter coefficient and exponent: ");
            scanf("%d %d", &coeff, &exp);
            poly2=insert_term(poly2,coeff,exp);
            break;
        case 3:
            result=polymultiplication(poly1,poly2);
            printf("Multiplication of two polynomials:\n");
            display(result);
            break;
        case 4:
            display(poly1);
            break;
        case 5:
            display(poly2);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);
}