#include <bits/stdc++.h>
using namespace std;
vector<int> low ;
vector<int> dt ;
void dfs_artic(Graph & g , int par , int src){
    low[src] = dt[src] = ++timer;
    int children = 0;
    for(int v : g.l[src]){
        if(dt[src]==-1){
            children ++;
            dfs_artic(g,src,v);
            low[src] = min(low[src],low[v]);
            if(par!=-1&&low[v]>=dt[src]){
                printf("Artic Point %d",src);
            }
        }
        else if(v != par){
            low[src] = min(low[src],dt[v]);
        } 
    }
    if(par==-1&&children>1){
        printf("Artic point %d",src);
    }
}

int main() {
    return 0;
}