#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int> &wts , vector<int> &vals , int index , int weight){
    if(weight == 0) return 0;
    if(index ==0 ){
        if(weight%wts[0]==0)return vals[0]*weight/wts[0];
        else return -1e9;
    }
    int notpick = unboundedKnapsack(wts,vals,index-1,weight);
    int pick = -1e9;
    if(wts[index]<=weight)pick = unboundedKnapsack(wts,vals,index,weight-wts[index]) + vals[index];
    return max(pick,notpick);
}

int main() {
    
    return 0;
}