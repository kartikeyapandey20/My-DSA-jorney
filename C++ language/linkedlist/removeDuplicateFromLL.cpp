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

        cout << "Memory is free from data and node " << value << endl;
    }
};

void print(Node * &head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp ->next;
    }cout << "NULL";
    cout << endl;
}
void insertAtHead(Node * &head,int d){

    //new node creation
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node * uniqueLL(Node * head){
    // empty list
    if(head == NULL){
        return NULL;
    }  
    //non empty list
    Node * curr = head;
    while(curr != NULL){
        if((curr -> next != NULL ) && curr -> data == curr -> next -> data){
            Node * temp = curr ->next ->next;
            Node * nodeToDelete = curr -> next  ;
            delete(nodeToDelete);
            curr -> next = temp;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}
int main(){
    Node * head = new Node(5);
    insertAtHead(head ,4);
    insertAtHead(head ,4);
    insertAtHead(head ,3);
    insertAtHead(head ,3);
    insertAtHead(head ,2);
    insertAtHead(head ,2);
    insertAtHead(head ,1);
    print(head);

    head = uniqueLL(head);
    // head = uniqueLL(head);
    print(head);
    return 0;
}