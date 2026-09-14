#include <bits/stdc++.h>
using namespace std;

int MaxWtAllowed(vector<int> &wts , vector<int> &vals , int index , int wt){
    if(wt==0) return 0;
    if(index == 0) {
        if(wts[0]<=wt) return vals[0];
        else return 0;
    }
    int nottake = MaxWtAllowed(wts,vals,index-1,wt);
    int take = -1e9;
    if(wts[index]<=wt){
        take =vals[index]+MaxWtAllowed(wts,vals,index-1,wt-wts[index]);
    }
    return max(take,nottake);
}

int memoization(vector<int> & wts , vector<int> & vals , int index , int wt , vector<vector<int>> dp){
    if(wt==0) return 0;
    if(index == 0) {
        if(wts[0]<=wt) return vals[0];
        else return 0;
    }
    if(dp[index][wt]!=-1)return dp[index][wt];
    int nottake = MaxWtAllowed(wts,vals,index-1,wt);
    int take = -1e9;
    if(wts[index]<=wt){
        take =vals[index]+MaxWtAllowed(wts,vals,index-1,wt-wts[index]);
    }
    return dp[index][wt] = max(take,nottake);
}

int tabulation(vector<int>& vals ,vector<int> & wts  , int wt ){
    int n = vals.size();
    vector<vector<int>> dp(n,vector<int>(wt+1,0));
    for(int i = 0 ;i < n ; i++)dp[i][0] = 0;
    for(int cap = wts[0] ; cap <= wt ; cap++)dp[0][cap] = vals[0];
    for(int index = 1 ; index < n ; index++){
        for(int cap = 0 ; cap < wt+1 ; cap++){
            int nottake  = dp[index-1][cap];
            int take = -1e9;
            if(wts[index]<=cap)take = vals[index] + dp[index-1][cap-wts[index]];
            dp[index][cap] = max(nottake,take);
        }
    }
    return dp[n-1][wt];

}

int optimal(vector<int>& vals ,vector<int> & wts  , int wt ){
    int n = vals.size();
    vector<int> prev(wt+1,0);
    prev[0] = 0;
    for(int cap = wts[0] ; cap <= wt ; cap++)prev[cap] = vals[0];
    for(int index = 1 ; index < n ; index++){
        vector<int> curr(wt+1,0);
        curr[0] = 0;
        for(int cap = 0 ; cap < wt+1 ; cap++){
            int nottake  = prev[cap];
            int take = -1e9;
            if(wts[index]<=cap)take = vals[index] + prev[cap-wts[index]];
                curr[cap] = max(nottake,take);
        }
        prev = curr;
    }
    return prev[wt];

}

int main() {
    
    return 0;
}