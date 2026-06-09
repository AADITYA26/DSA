#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

void TreePaths(Node * root , vector<int>&path, vector<vector<int>>&ans){
   if(root == NULL) return ;
   path.push_back(root->data);
   if(root->left==NULL&&root->right==NULL){
    ans.push_back(path);
    return;
   }
   TreePaths(root->left,path,ans);
   TreePaths(root->right,path,ans);
}



int main(){
    vector<int> preOrder = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, 10, -1, -1, 7, -1, -1};
    Node * root = BuildTree(preOrder);
    vector<vector<int>> ans;
    vector<int> path;
    TreePaths(root , path , ans);
    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

}