#include <bits/stdc++.h>
using namespace std;

bool WildCardMatching(string & s1 , string & s2 , int i , int j){
    if(i<0&&j<0)return true;
    if(j<0){
        for(int index =i ; index >=0 ; index--){
            if(s1[index]!='*')return false;
        }
        return true;
    }
    if(i<0||j<0)return false;
    if(s1[i]==s2[j]||s1[i]=='?')return WildCardMatching(s1,s2,i-1,j-1);
    if(s1[i]=='*'){
        bool include = WildCardMatching(s1,s2,i,j-1);
        if(include)return true;
        bool notinclude = WildCardMatching(s1,s2,i-1,j);
        return include || notinclude;
    }
    return false;
}

bool Memoization(string & s1, string & s2 , int i , int j, vector<vector<int>> &dp){
    if(i<0&&j<0)return true;
    if(j<0){
        for(int index =i ; index >=0 ; index--){
            if(s1[index]!='*')return false;
        }
        return true;
    }
    if(i<0||j<0)return false;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]||s1[i]=='?')return dp[i][j] =Memoization(s1,s2,i-1,j-1,dp);
    if(s1[i]=='*'){
        bool include = Memoization(s1,s2,i,j-1,dp);
        if(include)return dp[i][j] = true;
        bool notinclude = Memoization(s1,s2,i-1,j,dp);
        return dp[i][j] = include || notinclude;
    }
    return dp[i][j] = false;
}

bool tabulation(string s1 , string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int i = 1 ; i < n+1 ; i++){
        bool flag = true;
        for(int index =0 ; index <i ; index++){
            if(s1[index]!='*'){
                flag=false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for(int i = 1 ; i <n+1;i++){
        for(int j = 1 ; j < m+1 ;j++){
            if(s1[i-1]==s2[j-1]||s1[i-1]=='?')dp[i][j] = dp[i-1][j-1];
            else if(s1[i-1]=='*'){
                bool include = dp[i][j-1];
                if(include)dp[i][j] = true;
                bool notinclude = dp[i-1][j];
                dp[i][j] = include || notinclude;
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s1 = "*ay";
    string s2 = "rbay";
    cout<<tabulation(s1,s2);
    return 0;
}