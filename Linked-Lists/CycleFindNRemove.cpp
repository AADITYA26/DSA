#include <iostream>
#include "Introduction.cpp"
using namespace std;

void find_remove_cycle(List * myList){
    Node * slow = myList->head;
    Node * fast = myList->head;
    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    slow = myList->head;
    while(slow->next!=fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast->next->next = NULL;
}

int main(){
    List list;
    for(int i=1 ; i < 7 ; i++){
        list.push_back(i);
    }
    list.tail = list.head->next;
    list.print_list();
    find_remove_cycle(&list);
    list.print_list();
}