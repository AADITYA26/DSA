#include <bits/stdc++.h>
using namespace std;

int DistinctSubSeq(string & s1 ,string & s2 , int i , int j){
    if(j < 0) return 1;
    if(i < 0) return 0;
    int match = 0;
    if(s1[i]==s2[j]){
        match = DistinctSubSeq(s1,s2,i-1,j-1);
    }
    int notmatch = DistinctSubSeq(s1,s2,i-1,j);
    return match + notmatch;
}

int memoize(string & s1 , string & s2 , int i , int j , vector<vector<int>> &dp){
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int match = 0;
    if(s1[i]==s2[j]){
        match = memoize(s1,s2,i-1,j-1,dp);
    }
    int notmatch = memoize(s1,s2,i-1,j,dp);
    return dp[i][j] = match + notmatch;
}

int tabulation(string & s1 , string & s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 0; i < n+1 ; i++)dp[i][0] = 1;
    for(int j = 1 ; j < m+1 ; j++)dp[0][j] = 0;
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < m+1 ; j++){
            int match = 0;
            int notmatch = 0;
            if(s1[i-1]==s2[j-1]){
                match = dp[i-1][j-1];
            }
            notmatch = dp[i-1][j];
            dp[i][j] = notmatch+match;
        }
    }
    return dp[n][m];
}

int optimal(string & s1 , string & s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> dp(m+1,0);
    dp[0] = 1;
    for(int i = 1 ; i < n+1 ; i++){
        vector<int> curr(m+1,0);
        curr[0] = 1;
        for(int j = 1 ; j < m+1 ; j++){
            int match = 0;
            int notmatch = 0;
            if(s1[i-1]==s2[j-1]){
                match = dp[j-1];
            }
            notmatch = dp[j];
            curr[j] = notmatch+match;
        }
        dp = curr;
    }
    return dp[m];
}



int main() {
    string a = "babgbag";
    string b = "bag";
    vector<vector<int>> dp(a.length(),vector<int>(b.length(),-1));
    cout<<optimal(a,b);
    return 0;
}