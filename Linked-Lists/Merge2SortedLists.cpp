#include <iostream>
#include "Introduction.cpp"
using namespace std;

Node* Merge2SortedLists(Node * head1 , Node * head2){//making chnages to the list1 
    if(head1==NULL||head2==NULL) return (head1==NULL)?head2:head1;
    if(head1->data >= head2->data){
        Node * temp = Merge2SortedLists(head1,head2->next);
        head2->next = temp;
        return head2;
    }
    else{
        Node* temp = Merge2SortedLists(head1->next,head2);
        head1->next = temp;
        return head1;
    }
}

int main(){
    List* list1 = new List();
    List* list2 = new List();
    for(int i = 0 ; i<5 ; i++){
        list1->push_back(i*i-3);
    }
    for(int i = 0 ; i <7 ; i++){
        list2->push_back(i);
    }
    Node * head = Merge2SortedLists(list1->head,list2->head);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    
}
