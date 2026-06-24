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

vector<int> djikstraAlgo(vector<vector<Edge>> &g , int src){
    vector<int> dist(g.size(),INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dist[src]=0;
    q.push({0,src});
    while(!q.empty()){
        auto [d,u] = q.top();
        q.pop();
        if(d != dist[u])continue;//not necessary will work work wihtout this line too avoids repeat processing 
        //of some vertexes that have a higher distance pushed back in the queue
        for(Edge e: g[u]){
            int v = e.v;
            int wt = e.wt;
            if(dist[v]>dist[u]+wt){
                dist[v] = dist[u]+wt;
                q.push({dist[v],v});
            }
        }
    }
    return dist;
}