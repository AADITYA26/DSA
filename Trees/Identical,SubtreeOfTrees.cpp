#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;


bool Identical(Node * root1, Node* root2){
    if(root1==NULL||root2==NULL) return root1==root2;

    bool leftIdentical = Identical(root1->left , root2->left);//similar to the one we were doing before
    bool rightIdentical = Identical(root1->right , root2->right);

    return leftIdentical && rightIdentical&& root1->data == root2->data;
}

bool isSubtree(Node * root , Node * subroot){
    if(subroot==NULL) return true;
    if(root==NULL) return false;
    if(Identical(root,subroot)) return true;
    return isSubtree(root->left,subroot)||isSubtree(root->right,subroot);
}
