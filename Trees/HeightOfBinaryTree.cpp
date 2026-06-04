#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

int height(Node * root){
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight,rightHeight);
}

int count(Node * root){
    if(root == NULL) return 0 ;
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return 1+leftCount+rightCount;
}

int sum(Node * root){
    if(root == NULL ) return 0 ;
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return root->data + leftSum + rightSum;
}

int main(){
    vector<int> preOrder = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, 10, -1, -1, 7, -1, -1};
    Node * root = BuildTree(preOrder);
    cout<<sum(root)<<endl;

}