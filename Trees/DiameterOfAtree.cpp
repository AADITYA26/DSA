#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

int height(Node * root){
    if(root==NULL)return 0;
    int leftHeight = height(root->left);
    int rightHeight = height (root->right);
    return 1 + max (leftHeight,rightHeight);
}

int Diameter(Node * root ){
    if(root == NULL) return 0;
    int currDiameter = height(root->left)+height(root->right)+1;
    int leftDiameter = Diameter(root->left);
    int rightDiameter = Diameter(root->right);
    return max(currDiameter,max(leftDiameter,rightDiameter));
}

static int currDiameter = 0;

int height_Diameter(Node * root){
    if(root==NULL)return 0;
    int leftHeight = height_Diameter(root->left);
    int rightHeight = height_Diameter(root->right);
    currDiameter = max(leftHeight+rightHeight+1,currDiameter);//Calculating Diamter along with height to reduce time complexity to O(n)
    return 1 + max (leftHeight,rightHeight);
}

int main(){
    
}