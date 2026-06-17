//Linear Probing
#include<stdio.h>
#define SIZE 10
int hashTable[SIZE];
void initHashTable()
{
    for(int i=0;i<SIZE;i++)
        hashTable[i]=-1;
}
int hashFunction(int key) 
{
    return(key%SIZE);
}
void insert(int key)
{
    int index=hashFunction(key);
    while(hashTable[index]!=-1)
        index=(index+1)%SIZE;
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}
int search(int key)
{
    int index=hashFunction(key);
    while(hashTable[index]!=-1)
    {
        if(hashTable[index]==key)
            return index;
        index = (index + 1) % SIZE;
    }
    return -1;
}
void delete(int key)
{
    int index=search(key);
    if (index!=-1)
    {
        hashTable[index]=-1;
        printf("Deleted key %d at index %d\n", key, index);
    }
    else
        printf("Key %d not found in the hash table\n", key);
}
void display()
{
    printf("Hash Table:\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("[%d] -> ",i);
        if(hashTable[i]!=-1)
            printf("%d",hashTable[i]);
        else
            printf("Empty");
        printf("\n");
    }
}
void main()
{
    int x;
    initHashTable();
    insert(20);
    insert(30);
    insert(15);
    x=search(15);
    if(x==-1)
    printf("Element not found\n");
    else
        printf("Element found at index %d\n",x);
    printf("The elements are\n");
    display();
    delete(30);
    printf("After deleting, The elements are\n");
    display();
}