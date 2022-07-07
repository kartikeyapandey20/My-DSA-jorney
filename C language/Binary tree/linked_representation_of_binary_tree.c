#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *n;//CREATING A NODE POINTER
    n = (Node *)malloc(sizeof(Node)); //ALLOCATING MEMORY IN HEAP
    n->data = data;//SETTING THE DATA
    n->left = NULL;//SETTING LEFT AND CHILDREN RIGHT TO NULL
    n->right = NULL;//SETTING LEFT AND CHILDREN RIGHT TO NULL
    return n;
}
int main()
{
    /*
    (Method one for creating Node in binary tree)
    //CONSTUCTIONG THE ROOT NODE
    Node * p;
    p = (Node *)malloc(sizeof(Node));
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    // CONSTRUCTIONG THE SECOND NODE
    Node * p1;
    p1 = (Node *)malloc(sizeof(Node));
    p->data=1;
    p1->left=NULL;
    p1->right=NULL;

    //CONSTRUCTING THE THRID NODE
    Node * p2;
    p2->data=4;
    p2 = (Node *)malloc(sizeof(Node));
    p2->left=NULL;
    p2->right=NULL;

    //LINKING ROOT NODE WITH LEFT AND CHILDREN  CHILDREN
    p->left=p1;
    p->right=p2;
    */
    // Method 2 for creating node in a binary tree

    // Constructing the root node - using function(Recommended)
    Node *p = createNode(2);
    Node *p1 = createNode(1);
    Node *p2 = createNode(4);
    p->left=p1;
    p->right=p2;
    return 0;
}