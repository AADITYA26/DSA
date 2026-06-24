#include <bits/stdc++.h>
#include "Introduction.cpp"
using namespace std;

auto KahnsAlgorithm(Graph &g){
    queue<int> q ;
    vector<int> ans;
    vector<int> indegree(g.V,0);
    for(int i = 0 ; i < g.V ; i ++){
        for(int v  : g.l[i]){
            indegree[v]++;
        }
    }
    for(int i = 0 ; i < g.V ; i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for(int neighs : g.l[x]){
            indegree[neighs]--;
            if(indegree[neighs]==0)q.push(neighs);
        }
    }
    return ans;
}
