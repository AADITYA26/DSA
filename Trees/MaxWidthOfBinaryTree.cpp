#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;

int MaxWidth(Node * root){
    queue<pair<Node* , int>> q;
    q.push({root,0});
    int maxWidth = 0;
    while(!q.empty()){
        int levelSize = q.size();
        int startIndex = q.front().second;
        int endIndex = q.back().second;
        maxWidth = max(maxWidth , endIndex-startIndex+1);
        for(int i = 0 ; i < levelSize ; i ++){
            auto x  = q.front();
            q.pop();
            if(x.first->left) q.push({x.first->left , 2*x.second+1});
                if(x.first->right) q.push({x.first->right , 2*x.second+2});
        }
    }
    return maxWidth;
}

int main(){
    vector<int> preOrder = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, 10, -1, -1, 7, -1, -1};
    Node * root = BuildTree(preOrder);
    cout<<MaxWidth(root)<<endl;
}