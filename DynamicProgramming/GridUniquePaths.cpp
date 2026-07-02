#include <bits/stdc++.h>
using namespace std;

int GridPaths(int n , int m){
    if(n==0&&m==0)return 1;
    if(n<0||m<0)return 0;
    int up = GridPaths(n , m-1);
    int left = GridPaths(n-1 , m);
    return up+left;
}

int GridPaths_memoization(int n, int m, vector<vector<int>> dp){
    if(n==0&&m==0)return 1;
    if(n<0||m<0)return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int up = GridPaths_memoization(n , m-1,dp);
    int left = GridPaths_memoization(n-1 , m,dp);
    return dp[n][m] =  up+left;
}

int GridPaths_tabulation(int n , int m){
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0 ; i <n ; i++){
        for(int j = 0 ; j <m ; j++){
            if(i==0&&j==0){
                dp[i][j]=1;
                continue;
            }
            int up = 0;
            int left = 0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            dp[i][j] = up+left;
        }
    }
    return dp[n-1][m-1];
}

int GridPaths_optimal(int n, int m){
    vector<int> prev(m,0);
    for(int i = 0 ; i < n ; i++ ){
        vector<int> temp(m,0);
        for(int j = 0 ; j < m ; j ++){
            if(i==0&&j==0) {
                temp[j] = 1;
                continue;
            }
            int up  = 0;
            int left = 0;
            if(i>0)up = prev[i-1];
            if(j>0)left = temp[j-1];
            temp[j] = up+left;
        }
        prev = temp;
    }
    return prev[m-1];
}

int main() {
    cout<<GridPaths_optimal(2,2);
    return 0;
}