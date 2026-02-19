#include <iostream>
#include "Introduction.cpp"
using namespace std;

Node * Middle(List * myList){//Slow fast pointer approach
    Node * slow = myList->head;
    Node * fast = myList->head;
    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    List list;
    for(int i = 1 ; i< 6 ; i++){
        list.push_back(i);
    }
    Node * node = Middle(&list);
    cout<<node->data<<endl;
}