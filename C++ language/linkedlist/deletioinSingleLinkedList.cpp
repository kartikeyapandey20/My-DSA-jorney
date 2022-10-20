#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free from data and node" << endl;
    }
};

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
class Insertion
{
public:
    void insertAtHead(Node *&head, int d)
    {

        // new node creation
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtend(Node *&tail, int d)
    {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }

    void insertInBetween(Node *&tail, Node *&head, int d, int position)
    {
        if (position == 1)
        {
            insertAtHead(head, d);
            return;
        }
        Node *temp = head;
        int cnt = 1;
        while (cnt < position)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAtend(tail, d);
            return;
        }
        Node *nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
};

class Deletion
{
public:
    void deletionAtPosition(int position, Node *&head)
    {
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            int cnt = 1;
            Node *current = head;
            Node *prev = NULL;
            while (cnt < position)
            {
                prev = current;
                current = current->next;
                cnt++;
            }
            prev -> next = current -> next;
            current -> next = NULL;
            delete current;
        }
    }
};
int main()
{
    Insertion insert;
    Deletion deletetion;
    Node *node1 = new Node(1);

    Node *head = node1;
    Node *tail = node1;
    insert.insertAtend(tail, 2);
    insert.insertAtend(tail, 3);
    insert.insertAtend(tail, 4);
    insert.insertAtend(tail, 5);
    deletetion.deletionAtPosition(5,head);
    print(head);
    return 0;
}