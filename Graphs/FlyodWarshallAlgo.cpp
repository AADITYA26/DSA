#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int wt;
    Edge(int u, int v , int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

vector<vector<int>> floydWarshall(vector<Edge> &g  , int n){
    const int INF = 1e9;
    vector<vector<int>> dist(n,vector<int>(n,INF));
    for(int i = 0 ; i < g.size() ; i ++){
        int u = g[i].u;
        int v = g[i].v;
        int wt = g[i].wt;
        dist[u][v] = wt;
    }
    for(int i = 0 ; i < n ; i++){
        dist[i][i]=0;
    }
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ;j ++){
                if (dist[i][k] != INF && dist[k][j] != INF)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i= 0 ; i < n ; i ++){
        if(dist[i][i]<0){
            cout<<"negative Weighted cycle detected"<<endl;
        }
    }
    
    return dist;
}