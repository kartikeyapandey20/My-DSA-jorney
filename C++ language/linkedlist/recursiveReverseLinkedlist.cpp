#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node creation
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}


void reverse(Node *&head, Node * curr , Node* prev){
    if(curr == NULL){
        head = prev;
        return ;
    }
    Node * forward = curr -> next;
    reverse(head , forward, curr);
    curr -> next = prev;
}
Node * reverseLinkedList(Node *&head )
{
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node * curr = head ;
    Node * prev = NULL;
    reverse(head , curr , prev);
    return head;
}
int main()
{

    Node *head = new Node(3);
    insertAtHead(head, 5);
    insertAtHead(head, 7);
    insertAtHead(head, 9);
    print(head);
    head = reverseLinkedList(head);
    print(head);
    return 0;
}