#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

class INFO{
public:
    int min;
    int max;
    int size;
    INFO(int min , int max , int size){
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

INFO LargestBST(Node * root){
    if(root == NULL ) {
        INFO x(INT_MAX , INT_MIN , 0);
        return x;
    } 
    INFO left = LargestBST(root->left);
    INFO right = LargestBST(root->right);
    if(root->data>left.max && root->data<right.min){
        int currMin = min(root->data , left.min);
        int currMax = max(root->data , right.max);
        int currsize = 1+left.size+right.size;
        INFO x(currMin,currMax,currsize);
        return x;
    }
    else{
        INFO x(INT_MIN , INT_MAX ,max(left.size,right.size));
        return x;
    }
}