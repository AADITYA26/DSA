#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string&s1,string&s2){
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0);
    for(int i =1 ; i < n+1 ; i++){
        vector<int> curr(m+1,0);
        for(int j = 1 ; j < m+1 ; j++){
            if(s1[i-1]==s2[j-1]){
                curr[j] = 1 + prev[j-1];
                continue;
            }
            curr[j] = max(prev[j] , curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int LongestPalindromicSubsequence(string&s1){
    string s2(s1);
    reverse(s2.begin(),s2.end());
    return LongestCommonSubsequence(s1,s2);
}

int main() {
    string a = "bbbab";
    cout<<LongestPalindromicSubsequence(a);
    return 0;
}