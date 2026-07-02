#include <bits/stdc++.h>
using namespace std;
//this is using adjacency matrix 
void DFS(vector<vector<int>>& matrix , int src , stack<int> &topo , vector<bool>& vis){
    vis[src] = true;
    for(int i = 0 ; i < matrix.size() ; i++){
        if(matrix[src][i]){
            if(!vis[i])
            DFS(matrix , i , topo , vis);
        }
    }
    topo.push(src);
}

void reverse_DFS(vector<vector<int>> &matrix , int src , vector<bool>& vis){
    vis[src] = true;
    cout<<src<<" ";
    for(int i = 0 ; i < matrix.size() ; i++){
        if(matrix[src][i]){
            if(!vis[i])
            reverse_DFS(matrix , i , vis);
        }
    }
}

void Kosarajus(vector<vector<int>> & matrix ){
    int n = matrix.size();
    vector<bool> vis(n,false);
    stack<int> topo;
    for(int i = 0 ; i <n ; i++){
        if(!vis[i])
        DFS(matrix,i,topo,vis);
    }
    vector<vector<int>> reverse_matrix(n,vector<int>(n,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j ++){
            reverse_matrix[i][j] = matrix[j][i];
        }
    }
    vis.assign(n,false);
    while(!topo.empty()){
        int v  = topo.top();
        topo.pop();
        if(!vis[v]){
            reverse_DFS(reverse_matrix , v , vis);
            cout<<endl;
        }
    }
}

//this is using adjacency list

void DFS_adjList(vector<vector<int>> &g , int src, vector<bool>& vis , stack<int> &topo){
    vis[src] = true;
    for(int v : g [src]){
        if(!vis[v]){
            DFS_adjList(g,v,vis,topo);
        }
    }
    topo.push(src);
}

void rev_DFS(vector<vector<int>> &rev , int src , vector<bool>& vis){
    vis[src] = true;
    cout<<src<<" ";
    for(int v : rev[src]){
        if(!vis[v])
        rev_DFS(rev,v,vis);
    }
}

void Kosarajus_adjList(vector<vector<int>> &g){
    int n = g.size();
    vector<bool> vis(n,false);
    stack<int> topo;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            DFS_adjList(g,i,vis,topo);
        }
    }
    vector<vector<int>> rev(n,vector<int>());
    for(int i= 0 ; i < n ; i++){
        for(int v  : g[i]){
            rev[v].push_back(i);
        }
    }
    vis.assign(n,false);
    while(!topo.empty()){
        int v  = topo.top();
        topo.pop();
        if(!vis[v]){
            rev_DFS(rev , v , vis);
            cout<<endl;
        } 
    }
}