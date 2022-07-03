#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node linkedlistTraversal(Node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL");
    printf("\n");
}

Node *deletionAtHead(Node *head)
{
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deletionAtEnd(Node *head)
{
    Node *p = head;
    Node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node *deletionAtIndex(Node *head, int index)
{
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
Node *deletionAtIndexMethod2(Node *head, int index)
{
    Node *p = head;
    Node *q = p->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

Node *deletionAtNode(Node *head, int element)
{
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (q->data != element && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data = element)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("The value is not present  in the linked list");
    }
    return head;
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    linkedlistTraversal(head);
    // deleting first element of the linked list
    //  head=deletionAtHead(head);
    //  linkedlistTraversal(head);

    // deleting element at a particular index
    // deletionAtIndex(head,2);
    // linkedlistTraversal(head);

    // deleting last element from linked list
    // deletionAtEnd(head);
    // linkedlistTraversal(head);

    // deleting element at particular value which is present in the linked list
    deletionAtNode(head, 3);
    linkedlistTraversal(head);
}