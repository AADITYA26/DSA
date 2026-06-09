#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

int Sum(Node * root){
    if(root == NULL) return 0;
    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);
    root->data += leftSum + rightSum;
    return root->data;
}
