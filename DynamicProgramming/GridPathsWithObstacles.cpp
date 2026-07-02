#include <bits/stdc++.h>
using namespace std;

int GridPath_Obstacles(vector<vector<int>> &matrix , int n , int m){
    if(n<0||m<0)return 0;
    if(matrix[n][m]==-1)return 0;
    if(n==0&&m==0) return 1;
    int up  = GridPath_Obstacles(matrix , n-1 , m);
    int left = GridPath_Obstacles(matrix , n , m-1);
    return up+left;
}

int tabulation(const vector<vector<int>> &matrix , int n , int m){
    if(n<=0 || m<=0) return 0;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j]==-1){
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0){
                dp[i][j] = 1;
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

int optimal(const vector<vector<int>> & matrix , int n , int m){
    vector<int> prev(m , 0);
    for(int i = 0 ; i < n ; i++){
        vector<int> temp(m,0);
        for(int j = 0 ; j < m ;j ++){
            if(matrix[i][j]==-1){
                temp[j]  = 0;
                continue;
            }
            if(i==0&&j==0){
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if(i>0)up = prev[j];
            if(j>0)left = temp[j-1];
            temp[j] = up+left;
        }
        prev = temp;
    }
    return prev[m-1];
}


int main() {
    vector<vector<int>> matrix = {{0,0,0},{0,-1,0},{0,0,0}};
    cout<<optimal(matrix , matrix.size() , matrix[0].size());
    return 0;
}