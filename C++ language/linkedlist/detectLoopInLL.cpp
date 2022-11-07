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

// normal approach
bool detectLoop(Node *head){
    if(head == NULL){
        return false;
    }
    map<Node*,bool> visited;

    Node * temp = head ;
    while(temp != NULL){

        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp ->next;
    }

    return false;  
}

// slow and fast pointer approach

bool detectLoopSlowFast(Node * head){
    Node * slow = head ;
    Node * fast = head;
    while(slow != NULL || fast != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
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

    //normal map approach 
    if(detectLoop(head)){
        cout << "cycle detected in linked list" << endl;
    }
    else{
        cout << "cycle not detected in linked list " << endl;
    }

    //slow and fast pointer approach
    if(detectLoopSlowFast(head)){
        cout << "cycle detected in linked list" << endl;
    }
    else{
        cout << "cycle not detected in linked list " << endl;
    }

    return 0;
}