#include <iostream>
#include "Introduction.cpp"
using namespace std;

bool hasCycle(List * myList){
    Node * slow = myList->head;
    Node * fast = myList->head;
    while(fast!=NULL&&fast->next!=NULL){//fast->next check for odd sized linked lists
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }   
    return false;
}

void find_remove_cycle(List * myList){
    Node * slow = myList->head;
    Node * fast = myList->head;
    bool flag = 0 ;
    while(fast!=NULL&&fast->next!=NULL){//fast->next check for odd sized linked lists
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            flag =1;
            break;
        }
    }
    if(flag==0){
        cout<<"No cycle detected"<<endl;
        return;
    }

    slow = myList->head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main(){
    List list;
    for(int i=1 ; i < 6 ; i++){
        list.push_back(i);
    }
    list.tail->next = list.head->next->next;
    Node * temp = list.head;
    for(int i = 0 ; i < 10 ; i++){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    find_remove_cycle(&list);
    list.print_list();
}