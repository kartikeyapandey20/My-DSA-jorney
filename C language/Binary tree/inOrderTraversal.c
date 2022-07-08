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
    Node *n;                          // CREATING A NODE POINTER
    n = (Node *)malloc(sizeof(Node)); // ALLOCATING MEMORY IN HEAP
    n->data = data;                   // SETTING THE DATA
    n->left = NULL;                   // SETTING LEFT AND CHILDREN RIGHT TO NULL
    n->right = NULL;                  // SETTING LEFT AND CHILDREN RIGHT TO NULL
    return n;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{

    // Constructing the root node - using function
    Node *p = createNode(4);
    Node *p1 = createNode(1);
    Node *p2 = createNode(6);
    Node *p3 = createNode(5);
    Node *p4 = createNode(2);

    // FINALLY TREE LOOKS LIKE THIS :
    //       4
    //      / \
    //     1   6
    //    / \
    // 5   2
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inOrder(p);
    return 0;
}