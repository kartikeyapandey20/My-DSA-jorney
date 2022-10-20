#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node * next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
    ~Node()
    {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next ;
            next = NULL;
        }
        cout << "Node has been destroyed" << value << endl;
    }
};

class Insertion
{
    public:
        void insertNode(Node * &tail , int element , int d)
        {
            //assuming element is present in the list

            //case 1 if list is empty
            if(tail == NULL)
            {
                Node * newNode = new Node(d);
                newNode -> next = newNode;
                tail = newNode;
                return;
            }
            // if list is not empty
            // assuming element is present in the list

            else
            {
                Node * current = tail;
                while(current -> data != element)
                {
                    current = current -> next;
                }
                // element found -> current is representing element wala node
                Node * temp = new Node(d);
                temp -> next = current -> next;
                current -> next = temp;

            }
        }
};

class Deletion{
    public:
        void deleteNode(Node * &tail, int value){
            //empty list

            if(tail==NULL){
                cout << "Linked list is empty" << endl;
                return;
            }
            else{
                Node * prev = tail;
                Node * current = prev -> next;
                while(current-> data != value){
                    prev = current;
                    current = current -> next;
                }

                prev -> next = current -> next;
                //1 node linked list case
                if (current == prev){
                    tail = NULL;
                }

                // greater than or equal to 2 node linked list
                else if(tail == current){
                    tail = prev;
                }
                current -> next = NULL;
                
                delete current;
            }
        }
};
void print(Node * tail)
{
    if(tail == NULL){
        cout << " The linked list is empty" << endl;
        return ;
    }
    Node * temp = tail;
    do{
        cout << tail -> data << " -> ";
        tail = tail -> next;
    }while(tail  != temp);
    cout << "NULL";
    cout << endl;
}
int main()
{
    Insertion insert;
    Deletion deletion;
    Node * tail = NULL;

    //empty list case 
    insert.insertNode(tail ,5,1);

    //inserting in a circular linked list
    insert.insertNode(tail ,1,2);
    insert.insertNode(tail ,2,3);
    insert.insertNode(tail ,3,4);
    insert.insertNode(tail ,4,5);
    print(tail);

    //deletion in a circular linked list
    deletion.deleteNode(tail , 5);
    print(tail);
    return 0;
}