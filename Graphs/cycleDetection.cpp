#include <bits/stdc++.h>
#include "Introduction.cpp"
using namespace std;

bool CycleDetectionHelper(Graph G , vector<bool> vis , int par , int src){
    vis[src] = true;
    for(int neigh : G.l[src]){
        if(!vis[neigh]){
            if(CycleDetectionHelper(G,vis,src,neigh)) return true;
        }
        else if(neigh != par){
                cout<<"Cycle Detected"<<endl;
                return true;
        }
    }
    return false;
}