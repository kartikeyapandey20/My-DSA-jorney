#include<iostream>
#include<map>
using namespace std;
class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


Node * startEndOfLoop(Node * head){
    Node * slow = head ;
    Node * fast = head;
    while(slow != NULL || fast != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }         
            return slow ;
        }
    }
    return head;
}
void insertAtHead(Node * &head,int d){

    //new node creation
    Node * temp = new Node(d);
    temp->next = head;
    head = temp;
}
int main(){
    Node * head = new Node(4);
    Node * tail = head;
    insertAtHead(head ,3);
    insertAtHead(head ,2);
    insertAtHead(head ,1);
    cout << head << endl;
    tail -> next = head -> next -> next;
    Node * loop = startEndOfLoop(head);
    cout << loop -> data << endl;
    

    return 0;
}