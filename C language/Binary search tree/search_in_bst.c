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

Node * search(Node * root, int key)
{
    //IF THERE IS NO MATCHING KEY IN THE TREE IF WILL RETURN NULL
    if(root == NULL)
    {
        return NULL;
    }
    //IF WE FIND THE KEY WE WILL THAT ROOT
    if(root->data==key)
    {
        return root;
    }
    //IF THE DATA OF THE ROOT IS GREATER THAN KEY WE DO RECURSIVE CALL FOR LEFT SIDE OF THE BST 
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    //IF THE DATA OF THE ROOT IS LESS THAN KEY WE DO RECURSIVE CALL FOR RIGHT SIDE OF THE BST 
    else
    {
        return search(root->right,key);
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
    Node * n = search(p,1);
    if(n!=NULL)
    {
    printf("FOUND : %d",n->data);   
    }
    else{
        printf("Element not found");
    }
    return 0;
}