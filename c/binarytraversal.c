#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *root = NULL;
void main()
{
    int choice, value;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert element\n2. Search element\n3. Find minimum element\n4. Find maximum element\n5. Print elements (in-order)\n6. Print elements (pre-order)\n7. Print elements (post-order)\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root=addn(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct node *found = search(root, value);
                if (found != NULL)
                    printf("Element %d found in the tree.\n", value);
                else
                    printf("Element %d not found in the tree.\n", value);
                break;
            case 3:
                if (root != NULL)
                {
                    struct node *min = findMin(root);
                    printf("Minimum element is %d\n", min->data);
                }
                else
                    printf("Tree is empty.\n");
                break;
            case 4:
                if (root != NULL)
                {
                    struct node *max = findMax(root);
                    printf("Maximum element is %d\n", max->data);
                }
                else
                    printf("Tree is empty.\n");
                break;
            case 5:
                printf("Elements in the tree (in-order): ");
                inorder(root);
                break;
            case 6:
                printf("Elements in the tree (pre-order): ");
                preorder(root);
                printf("\n");
                break;
            case 7:
                printf("Elements in the tree (post-order): ");
                postorder(root);
                printf("\n");
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
struct node *addn(struct node *root,int data)
{
    if(root==NULL)
    {
        root=(struct node *)malloc(sizeof(struct node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<root->data)
            root->left=addn(root->left,data);
        else if(data>root->data)
                root->right=addn(root->right,data);
    return root;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct node *search(struct node *root,int key)
{
    if(root==NULL||root->data==key)
        return root;
    else if(key<root->data)
            return search(root->left,key);
        else
            return search(root->right,key);
}
struct node *findMin(struct node *root)
{
    while(root->left!=NULL)
        {
            root=root->left;
        }
    return root;
}
struct node *findMax(struct node *root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
void print(struct node *root)
{
    inorder(root);
}