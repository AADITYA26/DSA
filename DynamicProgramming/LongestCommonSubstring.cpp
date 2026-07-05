#include <bits/stdc++.h>
using namespace std;

int longestsubstring(string &s1 ,string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i = 1; i < n + 1 ; i ++){
        for(int j = 1; j < m+1 ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans , dp[i][j]);
                continue;
            }
            dp[i][j] = 0;
        }
        }
    return ans;
}

int optimal(string &s1 , string&s2){
    int n = s1.size();
    int m  =s2.size();
    vector<int> prev(m+1,0);
    int ans = 0 ;
    for(int i = 1; i < n+1 ; i++){
        vector<int> curr(m+1,0);
        for(int j = 1 ; j < m+1 ; j++){
            if(s1[i-1]==s2[j-1]){
                curr[j] = 1 + prev[j-1];
                ans = max(ans,curr[j]);
                continue;
            }
            curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}

int main() {
    string a = "acjkd";
    string b = "bcjke";
    cout<<longestsubstring(a,b);
    return 0;
}