#include <iostream>
using namespace std;

// typedef Node * NODE;
// typedef List * LIST;

class Node{
public:
    int data ;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
public:
    int count = 0;
    Node * head;
    Node * tail;
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node * node = new Node(val);
        Node * temp = head;
        head = node;
        node->next = temp;
        if(count == 0){
            tail = node;
        }
        count++;
    }

    void push_back(int val){
        Node *node = new Node(val);

        if(count == 0){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
        count++;
    }

    int pop_front(){
        if(count == 0 ){
            cout<<"The list is empty"<<endl;
            return 0;
        }
        Node *temp = head;      // save node
        int val = head->data;
        head = head->next;      // move head FIRST
        delete temp;            // then delete

        count--;

        if(count == 0)          // list became empty
            tail = NULL;

        return val;
    }


    int pop_back(){
        int val = 0;
        if(count == 0 ){
            cout<<"The list is empty"<<endl;
            return 0;
        }
        if(count ==1 ){
            val = head->data;
            delete head;
            head = NULL;
            tail =NULL;
            count --;
            return val;
        }
        Node * curr = head;
        while(curr->next->next!=NULL){
            curr= curr -> next;
        }
        val = curr->next->data;
        tail = curr;
        delete curr->next;
        curr->next  = NULL;
        count--;
        return val;
    }

    void print_list(){
        Node * curr = head;
        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

    void insert(int val, int pos){
        if(pos < 0 || pos > count){
            cout << "Invalid position\n";
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        if(pos == count){
            push_back(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;

        for(int i = 0; i < pos - 1; i++){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }


    int Search(int val){
        Node *temp = head;
        int pos = 0;

        while(temp != NULL){
            if(temp->data == val)
                return pos;
            temp = temp->next;
            pos++;
        }

        return -1;
    }

};

