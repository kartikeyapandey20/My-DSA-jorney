#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node * next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node * kReverseNode(Node * head, int k){
    // base case
    if(head == NULL){
        return NULL;
    }
    //step 1
    Node * next = NULL;
    Node * curr = head;
    Node * prev = NULL;

    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 recurssion dekh lega

    if(next != NULL){
        head -> next = kReverseNode(next , k);
    }
    //step 3 return head of reversed linked list

    return prev;   
}

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
int main(){

    Node *  head = new Node(1);
    insertAtHead(head , 2);
    insertAtHead(head , 3);
    insertAtHead(head , 4);
    insertAtHead(head , 5);
    insertAtHead(head , 6);
    print(head);

    cout << "After" << endl;

    head = kReverseNode(head , 2);
    print(head);
    return 0;
}