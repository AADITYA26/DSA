#include <bits/stdc++.h>
#include "Introduction.cpp"
#include <algorithm>
using namespace std;

// void CycleDetection(Graph & g){
//     vector<bool> vis(g.V,0);
//     vector<int> path;
//     for(int i = 0 ; i < g.V ; i++){
//         path.clear();
//         if(!vis[i]){
//             Cycle_Directed_Graph(g,vis,path,i);
//         }
//     }
// }


// void Cycle_Directed_Graph(Graph &g , vector<bool> &vis , vector<int>& path , int src){
//     vis[src] = true;
//     path.push_back(src);
//     for(int neigh : g.l[src]){
//         if(!vis[neigh]){
//             Cycle_Directed_Graph(g,vis,path,neigh);
//         }
//         else if(vis[neigh]&&(find(path.begin(),path.end(),neigh)!=path.end())){
//             cout<<"Cycle Detected";
//         }
//     }
// }


bool Cycle_Detection_Directed(Graph&g , vector<bool>&vis , vector<bool>&InStack , int src){
    InStack[src] = true;
    vis[src] = true;

    for(int neigh : g.l[src]){
        if(!vis[neigh]){
            if(Cycle_Detection_Directed(g,vis,InStack,neigh)) return true;
        }
        else if(InStack[neigh]){
            cout<<"Cycle Detected"<<endl;
            return true;
        }
    }
    InStack[src] = false;
    return false;
}

void Cycle(Graph & g){
    vector<bool> vis(g.V,0);
    vector<bool> InStack(g.V,0);
    for(int i = 0 ; i< g.V ; i++){
        if(!vis[i]){
            if(Cycle_Detection_Directed(g,vis,InStack,i))
            cout<<"Cycle Detected"<<endl;
        }
    }
}