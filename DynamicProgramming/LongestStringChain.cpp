#include <bits/stdc++.h>
using namespace std;

bool compare(string s1 , string s2){
    int n = s1.size();
    int m = s2.size();
    if(n!=m+1)return false;
    int i = 0;
    int j = 0;
    while(i<n && j < m){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            i++;
        }
    } 
    if(i==n&&j!=m)return false;
    return true;
}

int longestStringChain(vector<string> & strings){
    sort(strings.begin(),strings.end() , [](const string &a , const string &b)->bool{return a.size()<b.size();});
    int n =strings.size();
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(compare(strings[i],strings[j])){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}

int main() {
    vector<string> strings = {"a","b","bdcae","ba","ab","bca","bdca"};
    cout<<longestStringChain(strings);
    return 0;
}