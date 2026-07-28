#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int size = s.length();
    for(int i = 0 ; i < size/2 ; i++){
        if(s[i]!=s[size-1 -i])return false;
    }
    return true;
}

int PalindromePartitioning(string s , int i , int n){
    if(i == n)return 0;
    string temp = "";
    int mini = 1e9;
    for(int j = i ; j < n ; j++){
        temp+=s[j];
        if(isPalindrome(temp)){
            if(j==n-1)mini = min(mini,0);
            else mini = min(1+PalindromePartitioning(s,j+1,n),mini);
        }
    }
    return mini;
}

int tab(string s){
    int n = s.length();
    vector<int> dp(n+1,0);
    for(int i = n-1 ; i >= 0 ; i--){
        string temp = "";
        int mini = 1e9;
        for(int j = i ; j < n ; j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                if(j==n-1)mini = min(mini,0);
                else mini = min(1+dp[j+1],mini);
            }
        }
        dp[i] = mini;
    }
    return dp[0];
}

int main() {
    string s = "ababbbabbababa";
    cout<<tab(s);
    return 0;
}