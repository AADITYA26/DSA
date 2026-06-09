#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

Node * InorderPredeccessor(Node * root){
    Node * pred = root;
    if(pred==NULL)return NULL;
    if(pred->left!=NULL){
        pred = pred->left;
    }
    while(pred->right!=NULL&&pred->right!=root){
        pred = pred->right;
    }
    return pred;
}

void MorrisInorderTraversal(Node * root){
    Node * curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            Node * IP = InorderPredeccessor(curr);
            if(IP->right == NULL){
                IP->right = curr;
                curr = curr->left;
            }
            else{
                IP->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}