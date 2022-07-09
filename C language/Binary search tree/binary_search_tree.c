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

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
//FUNCTION FOR CHECKING IF BINARY TREE IS A BINARY SEARCH TREE OR NOT 
int isBST(Node *root)
{
    static Node *  prev=NULL;
    if(root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        //CHECKING IF PREVIOUR NODE IS NULL OR NOT AND COMPARING ITS VALUE WITH CURRENT ROOT NODE
        if(prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        // ASSGINING VALUE TO THE ROOT NODE
        prev=root;
        // RETURN RIGHT OF ROOT NODE FOR RECURSIVE CALL AND CHECKING OF THE BST
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main()
{

    // Constructing the root node - using function
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
    printf("\n");
    printf("%d",isBST(p));
    return 0;
}