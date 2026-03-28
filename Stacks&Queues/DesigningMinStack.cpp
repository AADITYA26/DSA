#include <bits/stdc++.h>
using namespace std;
//design a stack wiht the following functions 
//top,pop,push,getMin(for the minimum element)

class MinStack1{
public:
    stack<pair<int,int>> s;
    void push(int val){
        if(s.empty()){ 
            s.push({val,val});
            return;
        }
        int MinVal = s.top().second;
        s.push({val,min(val,MinVal)});
    }
    void pop(){
        if(s.empty()) return;
        s.pop();
    }
    int top(){
        if(s.empty())throw runtime_error("Stack is Empty");        
        return s.top().first;
    }
    int getMin(){
        if(s.empty()) throw runtime_error("Stack is Empty");
        return s.top().second;
    }
};

class MinStack2{//this just uses a global variable minVal
//though after popping an elemnt from the stack approach:
private:
int minVal;
public:
stack<long long int> s;
    void push(int val){
        if(s.empty()){
            s.push(val);
            minVal = val;
            return;
        }
        if(val < minVal) {
            s.push(2*val-minVal);
            minVal = val;
        }
        else {
            s.push(val);
        }
    }
    int getMin(){
        if(s.empty()) throw runtime_error("Stack is Empty");
        return minVal;
    }
    void pop(){
        if(s.empty()) throw runtime_error("Stack is Empty");
        if(s.top()<minVal){
            minVal = 2*s.top()-minVal;
            s.pop();
        }
        else s.pop();
    }
    int top(){
        if(s.top()<minVal) return minVal;
        else return s.top();
    }
};



