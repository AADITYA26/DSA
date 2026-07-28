#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int>&cuts , int i , int j , vector<vector<int>>& dp){
    if(j<i)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini = 1e9;
    for(int k = i ; k <= j ; k ++){
        int cost = cuts[j+1]-cuts[i-1]+minCost(cuts,i,k-1,dp)+minCost(cuts,k+1,j,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}

int tabulation(vector<int> & cuts , int y ){
    int n = cuts.size();
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    cuts.push_back(y);
    cuts.insert(cuts.begin(),0);
    for(int i = n ; i > 0 ; i--){
        for(int j = i ; j < n+1 ; j++ ){
            int mini = 1e9;
            for(int k = i ; k <= j ; k++){
                int cost = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini = min(cost,mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n];
}

int main() {
    vector<int> cuts = {1,3,5,4};
    cout<<tabulation(cuts,7);
    return 0;
}