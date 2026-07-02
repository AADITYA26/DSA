#include <bits/stdc++.h>
using namespace std;


int triangleSum(vector<vector<int>> triangle , int i , int j){
    if(j>i) return 1e9;
    if(i==triangle.size()-1) return triangle[i][j];
    int down = triangle[i][j]+triangleSum(triangle,i+1,j);
    int diag = triangle[i][j]+triangleSum(triangle,i+1,j+1);
    return min(down,diag);
}

int triangleSum_memoization(vector<vector<int>> triangle , int i , int j , vector<vector<int>> dp){
    if(j>i) return 1e9;
    if(i==triangle.size()-1) return triangle[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int down = triangle[i][j]+triangleSum(triangle,i+1,j);
    int diag = triangle[i][j]+triangleSum(triangle,i+1,j+1);
    return dp[i][j] = min(down,diag);
}

int tabulation(vector<vector<int>> triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0] = triangle[0][0];
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i+1 ; j++){
            int down  = 1e9;
            int diag  = 1e9;
            if(i>0&&j<i)down =  dp[i-1][j] + triangle[i][j];
            if(j>0&&i>0)diag  = dp[i-1][j-1] + triangle[i][j];
            dp[i][j] = min(down,diag);
        }
    }
    return *min_element(dp[n-1].begin() , dp[n-1].end());
}

int optimal(vector<vector<int>> triangle){
    int n = triangle.size();
    vector<int> prev(n,0);
    prev[0] = triangle[0][0];
    for(int i = 1 ; i < n ; i++){
        vector<int> temp(i+1,0);
        for(int j = 0 ; j < i+1 ; j++){
            int down  = 1e9;
            int diag  = 1e9;
            if(i>0&&j<i)down =  prev[j] + triangle[i][j];
            if(j>0&&i>0)diag  = prev[j-1] + triangle[i][j];
            temp[j] = min(down,diag);
        }
        prev = temp;
    }
    return *min_element(prev.begin() , prev.end());
}

int main() {
    vector<vector<int>> triangle = {
    {2},
    {3, 4},
    {6, 5, 7},
    {4, 1, 8, 3}};
    cout<<optimal(triangle);
    return 0;
}