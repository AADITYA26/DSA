#include <bits/stdc++.h>
#include "Introduction.cpp"
using namespace std;

vector<int> dt;
vector<int> low;
int timer = 0;
unordered_set<int> articulation_points ;
void dfs_artic(Graph&g , int src , int par){
    dt[src] = low[src] = ++timer;
    int children = 0;
    for(int v : g.l[src]){
        if(dt[v]==-1){
            children ++;
            dfs_artic(g,v,src);
            low[src] = min(low[src],low[v]);
            if(par!=-1 && low[v]>=dt[src]){//dont check root the condition for it are different 
                articulation_points.emplace(src);
            }
        }
        else if(v!=par){
            low[src] = min(low[src] , dt[v]);
        }
    }
    if(par==-1&&children >1){
    articulation_points.emplace(src);
    }
}

int main(){
    int nodes = 5;
    Graph g(nodes);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);

    dt.resize(5,-1);
    low.resize(5);
    for(int i = 0 ;i < nodes ; i++){
        if(dt[i]==-1)
        dfs_artic(g,i,-1);
    }
    for(int i :articulation_points){
        cout<<format("Articulation Point : {}",i)<<endl;
    }
}