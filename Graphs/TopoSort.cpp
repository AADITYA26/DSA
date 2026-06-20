#include <bits/stdc++.h>
#include "Introduction.cpp"
using namespace std;


void dfs_topo(Graph & g , int src , vector<bool> &visited , stack<int>& topo){
    visited[src] = true;
    for(int neigh : g.l[src]){
        if(!visited[neigh])
            dfs_topo(g,neigh,visited ,topo);
    }
    topo.push(src);
}

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    vector<bool> vis(g.V,false);
    stack<int> topo;
    for(int i = 0 ; i < g.V ; i++){
        if(!vis[i])dfs_topo(g,i,vis,topo);
    }
    int sz = topo.size();
    for(int i = 0 ; i < sz ; i++){
        int x = topo.top();
        topo.pop();
        cout<<x<< " ";  
    }
    
}

