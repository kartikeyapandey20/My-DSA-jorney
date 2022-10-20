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

void insertAtend(Node * &tail, int d)
{
    Node * temp = new Node(d);
    tail ->next = temp;
    tail = temp;
}

void insertInBetween(Node * &tail,Node * &head ,int d , int position){
    if(position==1){
        insertAtHead(head , d);
        return ;
    }
    Node * temp = head ;
    int cnt = 1;
    while(cnt < position){
        temp = temp -> next; 
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtend(tail , d);
        return ;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp ->next = nodeToInsert;
} 
int main()
{
    Node * node1 = new Node(12);
    cout << node1 -> data << endl;
    cout << node1 ->next << endl;

    Node * head = node1;
    Node * tail = node1;
    insertAtHead(head , 1);
    insertAtHead(head , 2);
    insertAtHead(head , 3);
    insertAtHead(head , 4);
    insertAtHead(head , 5);
    insertAtend(tail,13);
    insertAtend(tail,14);
    insertAtend(tail,15);
    insertAtend(tail,16);
    insertAtend(tail,17);
    insertInBetween(tail ,head , 11 , 5);
    insertInBetween(tail ,head , 1 , 1);
    print(head);
    return 0 ;

}