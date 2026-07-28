#include <bits/stdc++.h>
using namespace std;

int MCM(vector<int> & dims , int i , int j){
    if(i == j)return 0;
    int mini = 1e9;
    for(int k = i ; k < j ; k++){
        int steps = dims[i-1]*dims[k]*dims[j]+MCM(dims,i,k) + MCM(dims,k+1,j);
        mini = min(mini , steps);
    }
    return mini;
}

int memozation(vector<int>& dims , int i , int j , vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini  =1e9;
    for(int k = i ; k < j ; k ++){
        int steps = dims[i-1]*dims[k]*dims[j]+memozation(dims,i,k,dp) + memozation(dims,k+1,j,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}

int tabulation(vector<int> & dims){
    int n = dims.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i = 0 ; i < n ; i ++) dp[i][i] = 0;
    for(int i = n-1 ; i > 0 ; i--){
        for(int j = i+1 ; j <n ; j++){
            int mini = 1e9;
            for(int k = i ; k < j ; k++){
                int steps = dims[i-1]*dims[k]*dims[j]+ dp[i][k] + dp[k+1][j];
                mini = min(mini,steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

int main() {
    vector<int> dims = {10,20,30,40,50};
    int n = dims.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<tabulation(dims);
    return 0;
}