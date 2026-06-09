#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

void KthLevelOfBinaryTree(Node * root , int k , vector<int>& ans){
    if(root == NULL) return;
    if(k == 1 ) {
        ans.push_back(root->data);
        return;
    }
    k--;
    KthLevelOfBinaryTree(root->left , k , ans);
    KthLevelOfBinaryTree(root->right , k , ans);
}