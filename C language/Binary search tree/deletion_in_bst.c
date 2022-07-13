#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

Node *createNode(int data)
{
    Node *n;                          // CREATING A NODE POINTER
    n = (Node *)malloc(sizeof(Node)); // ALLOCATING MEMORY IN HEAP
    n->data = data;                   // SETTING THE DATA
    n->left = NULL;                   // SETTING LEFT AND CHILDREN RIGHT TO NULL
    n->right = NULL;                  // SETTING LEFT AND CHILDREN RIGHT TO NULL
    return n;
}

Node *itreativeSearch(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

Node * inOrderPredessor(Node * root)
{
    root = root->left;
    while (root->right!=NULL)
    {
        root= root ->right;
    }
    return root;
    
}
Node * deleteNode(Node * root , int value)
{
    Node * inOrderPre ;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left== NULL && root ->right == NULL)
    {
        free(root);
        return NULL;
    }
    //SEARCH FOR THE NODE TO BE DELETED 
    if(value < root->data)
    {
        root->left=deleteNode(root->left,value);
    }
    else if(value > root->data)
    {
        root->right=deleteNode(root->right,value);
    }
    //DELETION STRATEGY WHEN THE NODE IS FOUND 
    else{
        inOrderPre = inOrderPredessor(root);
        root->data = inOrderPre->data;
        root->left= deleteNode(root->left,inOrderPre->data);
    }
    return root;
}
int main()
{

    // CONSTRUCTING THE ROOT NODE - USING FUNCTION
    Node *p = createNode(5);
    Node *p1 = createNode(3);
    Node *p2 = createNode(6);
    Node *p3 = createNode(1);
    Node *p4 = createNode(4);

    // FINALLY TREE LOOKS LIKE THIS :
    //       5
    //      / \
    //     3   6
    //    / \
    //   1   4
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    deleteNode(p,3);
    printf("\n");
    inOrder(p);

       
    return 0;
}