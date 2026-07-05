#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string s1 , string s2 , int index1 , int index2){//printing the lcs
    if(index1 < 0 || index2 < 0) return "";
    if(s1[index1]==s2[index2])return longestCommonSubsequence(s1,s2,index1-1,index2-1)+s1[index1];
    string option1 = longestCommonSubsequence(s1,s2,index1-1,index2);
    string option2 = longestCommonSubsequence(s1,s2,index1,index2-1);
    return (option1.length()>option2.length())?option1:option2;
}

string lcs_memoization(string s1 , string s2 , int index1 , int index2 , vector<vector<string>>&dp){
    if(index1< 0 || index2<0) return "";
    if(dp[index1][index2]!="#")return dp[index1][index2];
    if(s1[index1]==s2[index2]) return dp[index1][index2] = lcs_memoization(s1,s2,index1-1,index2-1,dp)+s1[index1];
    string option1 = lcs_memoization(s1,s2,index1-1,index2,dp);
    string option2 = lcs_memoization(s1,s2,index1,index2-1,dp);
    return dp[index1][index2] = (option1.length()>option2.length())?option1:option2;
}//this approach time complexity will be O(nmL)

string lcs_tabulation(string &s1 , string & s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < m+1 ; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                continue;
            }
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int idx = dp[n][m]-1;
    string ans(idx+1, ' ');
    int i = n ;
    int j = m ;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans[idx--] = s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])i--;
            else j--;
        }
    }

return ans;
}

int main() {
    string a = "abcde";
    string b = "abcd";
    int n = a.length();
    int m = b.length();
    vector<vector<string>> dp(n,vector<string>(m,"#"));
    cout<<lcs_memoization(a,b,4,3,dp);
    return 0;
}