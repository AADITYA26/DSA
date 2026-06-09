#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

void SortedArray_BalancedBst(vector<int> arr , int start , int end , Node * &root){//O(nlog(n))
    if(start>end)return;
    int mid = start + (end-start)/2;
    insert(root,arr[mid]);
    SortedArray_BalancedBst(arr,start,mid-1,root);
    SortedArray_BalancedBst(arr,mid+1,end,root);
}

Node *  SortedArray_BalancedBst_Optimal(vector<int> arr , int start , int end ){//O(n)
    if(start>end)return NULL;
    int mid = start + (end-start)/2;
    Node * root = new Node(arr[mid]);
    root->left = SortedArray_BalancedBst_Optimal(arr,start,mid-1);
    root->right = SortedArray_BalancedBst_Optimal(arr,mid+1,end);
    return root;
}