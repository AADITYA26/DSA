#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

Node * GenBSTPRE_nonOptimal(vector<int>& preOrder , int preStart , int preEnd){//Split Point Method O(n^2)
    if(preStart > preEnd) return NULL;
    Node * root = new Node(preOrder[preStart++]);
    int it =preStart;
    while(it<=preEnd && preOrder[it]<root->data){
        it++;
    }
    root->left = GenBSTPRE_nonOptimal(preOrder , preStart , it-1);
    root->right  = GenBSTPRE_nonOptimal(preOrder , it , preEnd);
    return root;
}

Node * GenBSTPre(vector<int> &preOrder ,int & idx , int minVal , int maxVal){//O(n) abusing min and max of BST
    if(idx >= preOrder.size())return NULL;
    if(preOrder[idx] > maxVal || preOrder[idx] < minVal) return NULL;
    Node * root = new Node(preOrder[idx++]);
    root->left = GenBSTPre(preOrder , idx , minVal , root->data);
    root->right = GenBSTPre(preOrder , idx , root->data , maxVal);
    return root;
}

