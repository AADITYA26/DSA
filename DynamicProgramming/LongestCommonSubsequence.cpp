#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string longestCommonSubsequence(string s1 , string s2 , int index1 , int index2){//printing the lcs
    if(index1 < 0 || index2 < 0) return "";
    if(s1[index1]==s2[index2])return longestCommonSubsequence(s1,s2,index1-1,index2-1)+s1[index1];
    string option1 = longestCommonSubsequence(s1,s2,index1-1,index2);
    string option2 = longestCommonSubsequence(s1,s2,index1,index2-1);
    return (option1.length()>option2.length())?option1:option2;
}

int length_lcs(string &s1 , string &s2 , int index1 , int index2){
    if(index1 < 0 || index2 < 0) return 0;
    if(s1[index1]==s2[index2])return length_lcs(s1,s2,index1-1,index2-1)+1;
    int option1 = length_lcs(s1,s2,index1-1,index2);
    int option2 = length_lcs(s1,s2,index1,index2-1);
    return max(option1,option2);
}

int length_memoization(string &s1 , string &s2 , int index1 , int index2 , vector<vector<int>> dp){
    if(index1 < 0 || index2 < 0) return 0;
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    if(s1[index1]==s2[index2])return dp[index1][index2] = length_lcs(s1,s2,index1-1,index2-1)+1;
    int option1 = length_lcs(s1,s2,index1-1,index2);
    int option2 = length_lcs(s1,s2,index1,index2-1);
    return dp[index1][index2] = max(option1,option2);
}

int tabulation(string & s1 , string & s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));//already initializing dp[0][j]&&dp[i][0] as 0
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                continue;
            }
            int option1 = dp[i-1][j];
            int option2 = dp[i][j-1];
            dp[i][j] = max(option1,option2);
        }
    }
    return dp[n][m];
}

int optimal(string&s1 , string&s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0);//initializing the dp[0][j] as directly
    for(int i = 1; i < n+1 ; i++){
        vector<int> curr(m+1,0);
        for(int j = 1; j < m+1 ; j++){
            if(s1[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
                continue;
            }
            int option1 = prev[j];
            int option2 = curr[j-1];
            curr[j] = max(option1 , option2);
        }
        prev = curr;
    }
    return prev[m];
}

int main() {
    string a  = "abcde";
    string b = "ace";
    cout<<optimal(a,b);
    return 0;
}