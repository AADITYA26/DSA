#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

Node * nextRight = NULL;

void FlattenTree(Node * root ){
    if(root==NULL)return;
    FlattenTree(root->right);
    FlattenTree(root->left);
    root->left = NULL;
    root->right = nextRight;
    nextRight = root;
}

