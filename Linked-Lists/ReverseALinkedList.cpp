#include <iostream>
#include "Introduction.cpp"
using namespace std;

void Reverse(List * myList){
    Node * prev = NULL;
    Node * curr = myList->head;
    Node * next = curr->next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    myList->head = prev;
}

int main(){
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.print_list();
    Reverse(&list);
    list.print_list();
}