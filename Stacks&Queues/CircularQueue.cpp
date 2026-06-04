#include <bits/stdc++.h>
using namespace std;


class CircularQueue{
public:
    int capacity;
    int curr_size;
    int *arr;
    int front, rear;
    
    CircularQueue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        curr_size = 0;
    }

    void push(int val){
        if(curr_size == capacity) return;
        rear = (rear+1)%capacity;
        arr[rear] = val;
        curr_size++;
    }

    void pop(){
        if(curr_size==0) return;
        front = (front+1)%capacity;
        curr_size--;
    }

    int front(){
        if(curr_size == 0) return -1;
        else return arr[front];
    }

    bool empty(){
        return curr_size==0;
    }

};