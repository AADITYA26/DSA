#include <bits/stdc++.h>
using namespace std;

class LRUCache{
public:

    class Node {
    public:
        int key , val;
        Node * prev;
        Node * next;

        Node(int k, int v){
            key =k;
            val =v;
            prev = next = NULL;
        }
    };

    Node * head = new Node(-1,-1);
    Node * tail = new Node(-1,-1);

    unordered_map<int , Node*> map;

    void addNode(Node * newNode){
        
    }

    LRUCache(int capacity){
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){

    }

    void put(int key , int val){
        Node* newNode = new Node(key , val);
        addNode(newNode);


    }
};