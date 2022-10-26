#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node * next;

        Node(int value){
            this->data = value;
            this->next = NULL;
        }
};

void insertAtHead(Node * &head,int d){

    //new node creation
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node * &head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp ->next;
    }cout << "NULL";
    cout << endl;
}

Node * reverseLinkedList(Node *&head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node * perv = NULL;
    Node * curr = head;
    Node * forward = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = perv;
        perv = curr ;
        curr = forward;
    }
    return perv;
}
int main(){

    Node * head = new Node(3);
    insertAtHead(head,5); 
    insertAtHead(head,7); 
    insertAtHead(head,9);
    print(head); 
    head = reverseLinkedList(head);
    print(head);
    return 0;
}