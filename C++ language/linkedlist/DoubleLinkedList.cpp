#include <iostream>

using namespace std;
// class for the creation of the double linked list
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next == NULL)
        {
            delete next;
            this -> prev = NULL;
            this->next = NULL;
        }

        cout << "Memory is free from data and node" << endl;
    }
};

// method helps to get the length of the double linked list
int getLength(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

// method helps to print the double linked list
void print(Node *head)
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

class Insertion
{
public:
    void insertionAtHead(Node *&tail, Node *&head, int d)
    {

        if (head == NULL)
        {
            Node *temp = new Node(d);
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            Node *temp = new Node(d);
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }
    }

    void insertAtTail(Node *&tail, Node *&head, int d)
    {
        if (tail == NULL)
        {
            Node *temp = new Node(d);
            tail = temp;
            head = temp;
        }
        else
        {
            Node *temp = new Node(d);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insertAtPosition(Node *tail, Node *&head, int position, int d)
    {
        if (position == 1)
        {
            insertionAtHead(tail, head, d);
        }
        else
        {
            Node *current = head;
            Node *pre = NULL;
            int cnt = 1;
            while (cnt < position)
            {
                pre = current;
                current = current->next;
                cnt++;
            }

            if (current->next == NULL)
            {
                insertAtTail(tail, head, d);
                return;
            }

            Node *newNode = new Node(d);
            newNode->next = current;
            current->prev = newNode;

            pre->next = newNode;
            newNode->prev = pre;
        }
    }
};

class Deletion
{
public:
    void deletionAtPostion(Node * &head , Node * &tail , int position)
    {
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            head -> prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            int cnt = 1;
            Node *current = head;
            Node *pre = NULL;
            while (cnt < position)
            {
                pre = current;
                current = current->next;
                cnt++;
            }
            pre -> next = current -> next;
            pre -> prev = current -> prev;
            current->next = NULL;
            current->prev = NULL;
            delete current;
        }
    }
};

int main()
{
    Insertion insert;
    Deletion deletion;
    Node *node1 = new Node(2);
    print(node1);

    Node *head = node1;
    Node *tail = node1;

    // inserting value at the head
    insert.insertionAtHead(tail, head, 1);

    // inserting at the tail
    insert.insertAtTail(tail, head, 3);

    // insertion at position
    insert.insertAtPosition(tail, head, 2, 4);

    //deletion at position
    deletion.deletionAtPostion(head , tail , 1);

    // getting length of the double linked list
    cout << "The length of the double linked list is " << getLength(head) << endl;
    print(head);

    return 0;
}