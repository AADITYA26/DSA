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

int PrimsAlgo(vector<vector<Edge>> &g){
    unordered_set<int> MST;
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> q;
    int minCost = 0;
    q.push({0,0});
    while(!q.empty()){
        auto [d,u] = q.top();
        q.pop();
        if(MST.contains(u)) continue;
        minCost += d;
        MST.emplace(u);
        for(Edge e : g[u]){
            int v = e.v;
            int wt = e.wt;
            if(!MST.contains(v))
            q.push({wt,v});
        }
    }
    return minCost;
}