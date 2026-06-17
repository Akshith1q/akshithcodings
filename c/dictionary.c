#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int key;
    int value;
    struct node *next;
}*start = NULL;
void insert(int key,int value)
{
    struct node *temp = start;
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            temp->value = value; // update existing key
            return;
        }
        temp = temp->next;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->value = value; // fixed: assign value
    newnode->next = NULL;
    if(start == NULL)
        start = newnode;
    else 
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void deleteKey(int key)
{
    struct node *temp = start,*prev = NULL;
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            if(prev == NULL)
                start = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
int search(int key) 
{
    struct node *temp = start;
    while(temp != NULL) 
    {
        if(temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1; // not found
}
void display() 
{
    struct node *temp = start;
    while (temp != NULL) 
    {
        printf("Key: %d, Value: %d\n", temp->key, temp->value);
        temp = temp->next;
    }
}
void main() 
{
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    printf("Initial List:\n");
    display();
    int searchKey = 2;
    int searchResult = search(searchKey);
    if (searchResult != -1)
        printf("\nSearch result for key %d: %d\n", searchKey, searchResult);
    else
        printf("\nKey %d not found\n", searchKey);
    int delKey = 2;
    deleteKey(delKey);
    printf("\nList after deleting key %d:\n", delKey);
    display();
}