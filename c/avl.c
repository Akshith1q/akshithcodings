#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data, height;
    struct Node *left, *right;
}*root = NULL;
int height(Node *n)
{
    return n ? n->height : 0; 
}
int max(int a,int b)
{
    return a>b ? a : b;
}

struct Node* newNode(int v)
{
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = n->right = NULL; n->height = 1;
    return n;
}

static struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T = x->right;
    x->right = y;
    y->left = T;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

static struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T = y->left;
    y->left = x;
    x->right = T;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
int getBalance(struct Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}
struct Node *insert(struct Node *node, int key)
{
    if (!node)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int bal = getBalance(node);

    if (bal > 1 && key < node->left->data)
        return rightRotate(node);
    if (bal < -1 && key > node->right->data)
        return leftRotate(node);
    if (bal > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bal < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

static struct Node *minValueNode(struct Node *n)
{
    while (n->left)
        n = n->left;
    return n;
}

struct Node *deleteNode(struct Node *node, int key)
{
    if (!node)
        return NULL;
    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else
    {
        if (!node->left || !node->right)
        {
            struct Node *t = node->left ? node->left : node->right;
            if (!t)
            {
                free(node);
                return NULL;
            }
            *node = *t;
            free(t); /* copy contents and free child */
        }
        else
        {
            struct Node *t = minValueNode(node->right);
            node->data = t->data;
            node->right = deleteNode(node->right, t->data);
        }
    }
    if (!node)
        return NULL;
    node->height = 1 + max(height(node->left), height(node->right));
    int bal = getBalance(node);

    if (bal > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (bal > 1 && getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bal < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (bal < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(struct Node *n)
{
    printf("%d ", n->data);
    preorder(n->left);
    preorder(n->right);
}

struct Node *search(struct Node *n, int key)
{
    if (!n || n->data == key)
        return n;
    return key < n->data ? search(n->left, key) : search(n->right, key);
}

void main()
{
    int ch, val;
    do 
    {
        printf("\n1.Insert 2.Delete 3.Preorder 4.Search 5.Exit\nEnter choice: ");
        switch (ch)
        {
            case 1: printf("Insert: ");
                    scanf("%d", &val);
                    root = insert(root, val);
                    break;
            case 2: printf("Delete: ");
                    scanf("%d", &val);
                    break;
            case 2: printf("Delete: "); 
                    scanf("%d",&val); root = deleteNode(root,val); 
                    break;
            case 3: printf("Preorder: "); 
                    preorder(root); printf("\n"); 
                    break;
            case 4: printf("Search: "); 
                    scanf("%d",&val); printf(search(root,val) ? "Found\n" : "Not found\n"); 
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid\n");
        }
    } while(ch!=5);
}