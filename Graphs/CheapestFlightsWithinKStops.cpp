#include <bits/stdc++.h>
using namespace std;
//can convert to adjacency list for better time complexity
int CheapestFlight(int n , vector<vector<int>> &flights , int k , int src , int dst){//flight = (src,dest,cost)
    queue<vector<int>> q;//node cost stops
    q.push({src,0,-1});//a no stop flight will be 0 stops so src to src will be -1
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int u = x[0];
        int stops = x[2];
        int cost = x[1];
        for(auto flight : flights){
            if(flight[0]==u){
                if(dist[flight[1]]>cost+flight[2]&&stops+1<=k){
                    dist[flight[1]]=cost+flight[2];
                    q.push({flight[1],dist[flight[1]],stops+1});
                }
            }
        }
    }
    if(dist[dst]==INT_MAX)return -1;
    return dist[dst];
}

int main(){
    vector<vector<int>> flights = {{0, 1, 100},{1, 2, 100},{2, 0, 100},{1, 3, 600},{2, 3, 200}};
    cout<<CheapestFlight(4,flights,1,0,3)<<endl;
}