#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

Node * LCA (Node * root , Node * n1 , Node * n2){
    if(root == NULL) return NULL;
    if(root == n1 || root == n2 ) return root;
    Node * left = LCA(root->left , n1 , n2);
    Node * right = LCA(root->right , n1 , n2);
    if(n1!=NULL && n2!= NULL) return root;
    return ((left==NULL)?right:left);
}