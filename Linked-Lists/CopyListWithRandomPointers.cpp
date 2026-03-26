#include <iostream>
#include <unordered_map>
using namespace std;
//The definiton for Node has changed in this question so i cannot use the file Introduction .cpp
//Check you code at 
//https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*, Node*> map;
        Node* newHead = new Node(head->val);
        map[head]= newHead;
        Node *newTemp = newHead;
        Node *ans = newHead;
        Node *oldTemp = head;
        head = head->next;
        while(head!=NULL){
            Node* copyNode = new Node(head->val);
            newHead->next = copyNode;
            map[head] = copyNode;
            newHead = newHead->next;
            head=head->next;
        }
        while(oldTemp != NULL && newTemp !=NULL){
            if(oldTemp->random ==NULL){
                newTemp->random = NULL;
            }
            else{newTemp->random = map[oldTemp->random];}
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }
        return ans;
    }
};