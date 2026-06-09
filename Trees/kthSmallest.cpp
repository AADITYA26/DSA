#include <bits/stdc++.h>
#include "BinarySearchTrees.cpp"
using namespace std;

void kthSmallest(Node * root ,  int &k){
    if(root == NULL) return;
    kthSmallest(root->left , k );
    k--;
    if(k == 0){ 
        cout<<root->data<<endl;
        return;
    }
    kthSmallest(root->right , k);
}

void kthLargest(Node * root ,  int &k){
    if(root == NULL) return;
    kthLargest(root->right , k );
    k--;
    if(k == 0){ 
        cout<<root->data<<endl;
        return;
    }
    kthLargest(root->right , k);
}

int main(){
    vector<int> vals = {
    50, 30, 70,
    20, 40, 60, 80,
    10, 25, 35, 45,
    55, 65, 75, 90
};
    Node * root  = buildBST(vals);
    int k =4;
    kthLargest(root , k);
}