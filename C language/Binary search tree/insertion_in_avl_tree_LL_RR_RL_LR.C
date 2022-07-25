#include <stdio.h>
#include <stdlib.h>
// STRUCTURE FOR AVL TREE
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

//FUNCTION FOR GETTING MAXIMUM
int max(int a, int b)
{
    return (a > b) ? a : b;
}

//FUNCTION FOR GETTING THE HEIGHT OF TREE
int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1+max(getHeight(root->left), getHeight(root->right));
}

//FUNCTION FOR CREATING A NODE
Node *createNode(int data)
{
    Node *n;                          // CREATING A NODE POINTER
    n = (Node *)malloc(sizeof(Node)); // ALLOCATING MEMORY IN HEAP
    n->data = data;                   // SETTING THE DATA
    n->left = NULL;                   // SETTING LEFT AND CHILDREN RIGHT TO NULL
    n->right = NULL;                  // SETTING LEFT AND CHILDREN RIGHT TO NULL
    n->height = 1;
    return n;
}

//FUNCTION FOR GETTING THE BALANCE FACTOR OF THE TREE
int getBalanceFactor(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
    
// FUNCTION FOR ROTATING THE TREE IN RIGHT DIRECTION
Node *rightRotation(Node *y)
{

    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;

    //UPDATING THE HEIGHT OF THE TREE AFTER ROTAION
    y->height = getHeight(y);
    x->height = getHeight(x);

    return x;
}

//FUNCTION FOR ROTATING TREE IN LEFT DIRECTION
Node *leftRotation(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    //UPDATING THE HEIGHT OF THE TREE AFTER ROTATION
    y->height = getHeight(y);
    x->height = getHeight(x);

    return y;
}

//FUNCTION FOR INSETION NODE IN A AVL TREE
Node *insertInAvl(Node *node, int key)
{
    if (node == NULL)
    {
        return (createNode(key));
    }

    if (key < node->data)
    {
        node->left = insertInAvl(node->left, key);
    }
    else if (key > node->data)
        node->right = insertInAvl(node->right, key);
    else
    {
        return node;
    }

    node->height = getHeight(node);

    int bf = getBalanceFactor(node);

    // LEFT LEFT ROTATION
    if (bf > 1 && key < node->left->data)
    {
        return rightRotation(node);
    }
    // RIGHT RIGHT ROTATION
    if (bf < -1 && key > node->right->data)
    {
        return leftRotation(node);
    }
    // LEFT RIGHT ROTATION
    if (bf > 1 && key > node->left->data)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    // RIGHT LEFT ROTATION
    if (bf < -1 && key < node->right->data)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}

//FUNCTION FOR PREORDER TRAVERSAL
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//FUNCTION FOR INORDER TRAVERSAL
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
    Node *root = NULL;
    //INSERTING NODE IN AVL TREE
    root = insertInAvl(root, 1);
    root = insertInAvl(root, 2);
    root = insertInAvl(root, 3);
    root = insertInAvl(root, 4);
    root = insertInAvl(root, 5);
    root = insertInAvl(root, 6);
    //DOING PREORDER TRAVERSAL FOR CHECKING IF INSERTION IS DONE PROPERLY OR NOT
    preOrder(root);
    printf("\n");
    //DOING INORDER TRAVERSAL FOR CHECKING IF INSERTION IS DONE PROPERLY OR NOT
    inOrder(root);

    return 0;
}