#include <bits/stdc++.h>
using namespace std;

int EditDistance(string & s1 , string & s2 , int i , int j){
    if(j<0&&i<0)return 0;
    if(j<0&&i>=0)return i+1;
    if(i < 0 && j >= 0) return j + 1;
    if(s1[i]==s2[j]){
        return 0 + EditDistance(s1,s2,i-1,j-1);
    }
    else{
        int insert = EditDistance(s1,s2,i,j-1);
        int del = EditDistance(s1,s2,i-1,j);
        int replace = EditDistance(s1,s2,i-1,j-1);
        return 1 + min({insert,del,replace});
    }
}


int memoize(string & s1 , string & s2 , int i , int j , vector<vector<int>> &dp){
    if(j<0&&i<0)return 0;
    if(j<0&&i>=0)return i+1;
    if(i < 0 && j >= 0) return j + 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j] = 0 + memoize(s1,s2,i-1,j-1,dp);
    }
        int insert = memoize(s1,s2,i,j-1,dp);
        int del = memoize(s1,s2,i-1,j,dp);
        int replace = memoize(s1,s2,i-1,j-1,dp);
        return dp[i][j] = 1 + min({insert,del,replace});
}

int tabulation(string & s1 , string & s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0] = 0;
    for(int i = 1 ; i < n+1 ; i++)dp[i][0] = i;
    for(int j = 1 ; j < m+1 ; j++)dp[0][j] = j;
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < m+1 ; j++){
            if(s1[i-1]==s2[j-1])dp[i][j] = dp[i-1][j-1];
            else{
            int insert = dp[i][j-1];
            int del = dp[i-1][j];
            int replace = dp[i-1][j-1];
            dp[i][j] = 1 + min({insert,del,replace});
            }
        }
    }
    return dp[n][m];
}


int space_optimal(string & s1 , string & s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0);
    prev[0] = 0;
    for(int j = 1 ; j < m+1 ; j++)prev[j] = j;
    for(int i = 1 ; i < n+1 ; i++){
        vector<int> curr(m+1,0);
        curr[0] = i;
        for(int j = 1 ; j < m+1 ; j++){
            if(s1[i-1]==s2[j-1])curr[j] = prev[j-1];
            else{
            int insert = curr[j-1];
            int del = prev[j];
            int replace = prev[j-1];
            curr[j] = 1 + min({insert,del,replace});
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main() {
    string s1 = "babg";
    string s2 = "bag";
    vector<vector<int>> dp(4,vector<int>(3,-1));
    cout<<space_optimal(s1,s2);
    return 0;
}