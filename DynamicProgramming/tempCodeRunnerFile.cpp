#include <bits/stdc++.h>
using namespace std;

string shortCommonSuperSeq(string & s1 , string & s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1 ; i < n+1 ;i ++){
        for(int j = 1 ;j < m+1 ; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                continue;
            }
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int l = dp[n][m];
    int idx = n+m-l-1;
    string ans(n+m-l,' ');
    int i = n;
    int j = m;
    while(i > 0 && j>0){
            if(s1[i-1]==s2[j-1]){
            ans[idx--] = s1[i-1]; 
            --i;
            --j;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans[idx--] = s1[i-1];
                i--;
            }
            else{
                ans[idx--] = s2[j-1];
                j--;
            }
        }
    }
    for(int p = i ; p >0 ; p++){
        ans[idx--] = s1[p-1];
    }
    for(int q = j ; q > 0 ; q++){
        ans[idx--] = s2[q-1];
    }
    return ans;
}

int main() {
    string a = "brute";
    string b = "groot";
    cout<<shortCommonSuperSeq(a,b);
    return 0;
}