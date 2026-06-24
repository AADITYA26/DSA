#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

vector<int> bellmanFord(vector<vector<Edge>> g  ){
    vector<int> dist(g.size(),INT_MAX);
    dist[0]=0;
    for(int i = 0 ; i < g.size()-1 ; i ++){
        for(int u = 0 ; u < g.size() ; u++ ){
            for(Edge e : g[u]){
                if(dist[u]!=INT_MAX && dist[e.v]>dist[u]+e.wt){
                    dist[e.v] = dist[u]+e.wt;
                }
            }
        }
    }
    return dist;
}