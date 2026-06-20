#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

void RecoverBSThelper(Node * root , Node * & prev , Node * &first , Node * &second){
    if(root==NULL) return ;
    RecoverBSThelper(root->left , prev , first , second);
    if(prev!= NULL &&root->data<prev->data){
        if(first == NULL){ first = prev ; second = root;}//adjacent cases
        else second = root;
    }
    prev = root;
    RecoverBSThelper(root->right, prev , first , second);
}

void RecoverBST(Node * root){
    Node * prev =NULL , *first = NULL, *second = NULL;//incase prev is null for the first comparison 
    RecoverBSThelper(root , prev , first , second);
    swap(first->data , second->data);
    return;
}

//You can also do it using Morris Inorder Traversal if you want to have constant space

Node * inorder_pred(Node * root){
    if(root->left==NULL)return NULL;
    Node * curr = root;
    curr = curr->left;
    while(curr->right!=NULL&&curr->right!=root){
        curr = curr->right;
    }
    return curr;
}

void RecoverBst_MIT(Node * root)
{
    Node * first = NULL;
    Node * second = NULL;
    Node * prev = NULL;
    Node * curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            //visit
            if(prev!=NULL&&prev->data>curr->data){
                if(first==NULL){
                    first = prev;
                    second = curr;
                }
                else second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        else{
            Node * IP = inorder_pred(curr);
            if(IP->right == NULL){
                IP->right = curr;
                curr = curr->left;
            }
            else{
                IP->right = NULL;

                //visit
                if(prev!=NULL&&prev->data>curr->data){
                    if(first==NULL){
                        first = prev;
                        second = curr;
                    }
                    else second = curr;
                    }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    if(first!=NULL&&second!=NULL)
    swap(first->data,second->data);
}