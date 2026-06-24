#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>>& adj) {
    //Write your code here...
    enum COLOR {
        GRAY,
        RED ,
        WHITE
    };
    vector<COLOR> color(adj.size(),GRAY);
    queue<int> q;
    for(int i =0 ; i < adj.size() ; i++){
        if(color[i]!=GRAY) continue;
        q.push(i);
        color[i] = RED;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int neigh : adj[v]){
                if(color[neigh] ==GRAY){
                    q.push(neigh);
                    color[neigh] = color[v]==RED?WHITE:RED;
                }
                else if(color[neigh]==color[v]) return false;
                }
            }
    }
    return true;
}