#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;


bool validateBST(Node * root , int min/*long long min*/ , int max/*long long max*/ ){//switch to long long if the problem is about general validation
    if(root == NULL) return true;
    if(root->data < min || root->data >max) return false;
    return validateBST(root->left , min , root->data) && validateBST(root->right , root->data , max);
}