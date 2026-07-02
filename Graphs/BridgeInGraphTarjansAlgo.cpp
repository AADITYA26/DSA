#include <bits/stdc++.h>
#include "Introduction.cpp"
using namespace std;
vector<int> dt;
vector<int> low;
int timer = 0;
void dfs_Tarjans(Graph & g , int par , int src ){
    //vis[src] = true;//can use discovery time to track the connections
    dt[src]=low[src]=++timer;
    for(int neigh : g.l[src]){// 3 cases vis->par and not par  ,  unvis
        if(dt[neigh]==-1){
            dfs_Tarjans(g,src,neigh);
            low[src] = min(low[src],low[neigh]);
            if(low[neigh]>dt[src]){
                cout<<"Bridge Found at : "<< " ";
                cout<<format("Edge({},{})",src,neigh)<<endl;
            }
        }
        else if(neigh!=par){
            low[src] = min(dt[neigh],low[src]);
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(0,2);
    g.addEdge(3,4);
    dt.resize(g.V,-1);
    low.resize(g.V);
    for(int i = 0 ; i < g.V ; i ++){
        if(!dt[i]==-1)
        dfs_Tarjans(g,-1,0);

    }
}