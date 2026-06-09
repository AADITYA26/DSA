#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

void minimumDistance(Node * root , Node *& prev , int & ans){
    if(root == NULL) return ;
    minimumDistance(root->left,prev,ans);
    if(prev!=NULL){
        ans = min(ans , root->data-prev->data);
    }
    prev = root;
    minimumDistance(root->right,prev,ans);
}