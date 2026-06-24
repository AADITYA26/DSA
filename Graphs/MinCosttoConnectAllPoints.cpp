#include <bits/stdc++.h>
using namespace std;

int calculateWeight(pair<int,int> a , pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int MinCost(vector<pair<int,int>> points){//O(n^2) time and O(n) space 
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
    unordered_set<int> MST;
    int n = points.size();
    int cost = 0;
    q.push({0,0});
    while(!q.empty()){
        auto x  = q.top();
        cost += x.first;
        MST.emplace(x.second);
        q.pop();
        if(MST.size()==n)return cost;
        if(MST.contains(x.second))continue;
        for(int i = 0 ; i <n; i++){
            if(!MST.contains(i)){
                q.push({calculateWeight(points[x.second],points[i]),i});
            }
        }
    }
    return cost;
}


int MinCost_optimal(vector<pair<int,int>> points){//O(n^2) time and O(n) space
    int n = points.size();
    vector<int> Distance(n , INT_MAX);
    vector<bool> inMST(n , false);
    Distance[0] = 0;
    int minCost = 0;
    
    for(int i  = 0; i < n ; i++){
        int minIndex = -1;//making it 0 would cause it to malfunction and give 0 if does nt find any
        for(int j = 0 ; j < n ; j++){
            if(!inMST[j]&&(minIndex == -1||Distance[minIndex]>Distance[j])) minIndex = j;//finding the minimum distance from the array
        }
        if(minIndex == -1)continue;
        minCost+=Distance[minIndex];
        inMST[minIndex] = true;
        for(int j = 0 ; j < n ; j++){//changing the height after adding the vertex
            if(Distance[j]>calculateWeight(points[minIndex],points[j])&&!inMST[j])//keeping the min distance always
                Distance[j] = calculateWeight(points[minIndex],points[j]);
        }

    }

    return minCost;
}

int main(){
    vector<pair<int,int>> p = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<MinCost_optimal(p)<<endl;
}