#include <bits/stdc++.h>
#include <list>//internally implement dll
using namespace std;


class Graph{
public:
    int V ;
    list<int> *l;
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i = 0 ;i < this->V ; i++){
            auto current = this->l[i].begin();
            while(current != this->l[i].end()){
                cout<<*current<<" ";
                current++;
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> vis(V,0);
        for(int i = 0 ; i < this->V ; i++){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
            }
            while(!q.empty()){
                int temp = q.front();
                cout<<temp<<" ";
                q.pop();
                for(int neigh : this->l[temp]){
                    if(!vis[neigh]){
                        vis[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        }
    }

    void dfsvisit(vector<bool>& vis , int i){
        cout<<i<<" ";
        vis[i]=true;
        for(int neigh : this->l[i]){
            if(!vis[neigh])
            dfsvisit(vis,neigh);
        }
    }

    void dfs(){
        vector<bool> vis(V,0);
        for(int i = 0 ; i <this->V ; i++){
            if(!vis[i])
            dfsvisit(vis,i);
        }
    }

    bool cycledetection(int src, int par , vector<bool> vis){
        vis[src] = true;
        for(int neigh : this->l[src]){
            if(!vis[neigh]){
                if(cycledetection(neigh , src , vis))return true;
            }
            else if(neigh==par)return true;
        }
        return false;
    }

    bool cycleDetectionBFS(){
        queue<pair<int,int>> q;
        vector<bool> vis(V,0);
        q.push({0,-1});
        vis[0] = true;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(int neigh : this->l[temp.first]){
                if(!vis[neigh]){
                    q.push({neigh,temp.first});
                    vis[neigh] = true;
                }
                else if(neigh == temp.second)return true;
            }

        }
    }

};

// int main(){
//     Graph g(5);

//     g.addEdge(0,1);
//     g.addEdge(1,2);
//     g.addEdge(1,3);
//     g.addEdge(2,3);
//     g.addEdge(2,4);
//     cout<<"Adjacency List"<< " ";
//     g.printAdjList();
//     cout<<endl;
//     vector<bool> vis(5,0);
//     if(g.cycledetection(0,-1,vis)) cout<<"Cycle Detected"<<endl;
//     return 0;

// }