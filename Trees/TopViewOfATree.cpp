#include <bits/stdc++.h>
#include "BinaryTrees.cpp"
using namespace std;
void topView(Node *root){
    queue<pair<Node * , int>> q; //<node , Horizaontal Distance>
    q.push({root,0});//Dustance of the root is always 0
    map<int , int > m;//<Horizontal Distance , Data of the Node>
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(m.find(x.second)==m.end())
            m[x.second]= x.first->data;//Adding to the map if not there 
        if(x.first->left!=NULL)
            q.push({x.first->left,x.second-1});//pushing the pair of Node and Hd in the queue
        if(x.first->right!=NULL)
            q.push({x.first->right,x.second+1});
    }

    for(auto p : m){
        cout<<p.second<<" ";
    }
}

void bottomView(Node *root){
    queue<pair<Node * , int>> q; //<node , Horizaontal Distance>
    q.push({root,0});//Dustance of the root is always 0
    map<int , int > m;//<Horizontal Distance , Data of the Node>
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        m[x.second]= x.first->data;//Adding to the map if not there 
        if(x.first->left!=NULL)
            q.push({x.first->left,x.second-1});//pushing the pair of Node and Hd in the queue
        if(x.first->right!=NULL)
            q.push({x.first->right,x.second+1});
    }

    for(auto p : m){
        cout<<p.second<<" ";
    }
}

int main(){
    vector<int> preOrder = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, -1, -1, 3, 6, -1, 10, -1, -1, 7, -1, -1};
    Node * root = BuildTree(preOrder);
    topView(root);
    cout<<endl;
    bottomView(root);

}