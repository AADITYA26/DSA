#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> matrix , int n, int m){
    if(n==0 && m==0) return matrix[n][m];
    if(n<0||m<0) return 1e9;//directly using int max will cause it to return a negative number therefore billion is returned
    int up = matrix[n][m] + minPathSum(matrix,n-1,m);
    int left = matrix[n][m] + minPathSum(matrix,n,m-1);
    return min(left , up);
}

int minPathSum_memoization(vector<vector<int>> matrix , int n , int m , vector<vector<int>> dp){
    if(n==0 && m==0) return matrix[n][m];
    if(n<0||m<0) return 1e9;//directly using int max will cause it to return a negative number therefore billion is returned
    if(dp[n][m]!=-1)return dp[n][m];
    int up = matrix[n][m] + minPathSum(matrix,n-1,m);
    int left = matrix[n][m] + minPathSum(matrix,n,m-1);
    return dp[n][m] = min(left , up);
}

int tabulation(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i==0 && j==0){
                dp[i][j] = matrix[i][j];
                continue;
            }
            int up = 1e9;
            int left = 1e9;
            if(i>0) up = matrix[i][j] + dp[i-1][j];
            if(j>0) left = matrix[i][j] + dp[i][j-1];
            dp[i][j] = min(left,up);
        }
    }
    return dp[n-1][m-1];
}

int main() {
    
    return 0;
}