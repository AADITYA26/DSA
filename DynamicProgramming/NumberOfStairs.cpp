#include <bits/stdc++.h>
using namespace std;
//try all possible ways , best way ...  : recurison
int NumberOFStairs(int n){
    if(n==0)return 1;
    if(n==1)return 1;
    return NumberOFStairs(n-2)+NumberOFStairs(n-1);
}

int NumberOFStairs_memoization(int n , vector<int> &dp){
    if(n==0)return dp[0] = 1;
    if(n==1)return dp[1] = 1 ;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = NumberOFStairs_memoization(n-1,dp)+NumberOFStairs_memoization(n-2,dp);
}

int NumberOFStairs_optimal(int n){
    if(n==0||n==1)return 1;
    int prev = 1 , prev2 =1;
    int curr = 0;
    for(int i = 2 ; i <= n; i ++){
        curr = prev +prev2;
        prev2 = prev;
        prev =curr;
    }
    return curr;
}

int main() {
    cout<<NumberOFStairs_optimal(5);
    return 0;
}