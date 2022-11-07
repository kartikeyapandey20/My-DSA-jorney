#include<iostream>

using namespace std;

class Node {
    public:
        int data ;
        Node * next ;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node * &head,int d){

    //new node creation
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node * findMiddle(Node * head){
    Node * temp = head;
    int len = 0;
    int count = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    temp = head;

    while(count != ((len/2))){
        temp = temp -> next;
        count ++;
    }

    return temp;
}
int main(){ 
    Node * head =  new Node(3);
    insertAtHead(head,2);
    insertAtHead(head,1);

    Node * middle = findMiddle(head);

    cout << middle -> data << endl;
    return 0;
}