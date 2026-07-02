#include <bits/stdc++.h>
using namespace std;

int fib_memoization(int n , vector<int> & dp){//Recursion with  Memoization
    if(n<=1)return dp[n]=n;
    if(dp[n]!=-1)return dp[n];//Memoization
    return dp[n]= fib_memoization(n-1,dp)+fib_memoization(n-2,dp);
}

int fib_tabulation(int n){//Recursion space removed 
    vector<int> dp(n+1,-1) ;
    for(int i = 2 ; i < n ; i++){
        dp[i] = dp [i-1]+dp[i-2];
    }
    return dp[n];
}

int fib_optimal(int n){
    if(n<=1)return n;
    int prev = 1 ;
    int prev2 = 0;
    int curr = 0;
    for(int i = 2; i <= n ; i++){
        curr = prev +prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}



int main() {
    int n = 5;
    vector<int> dp(n+1,-1);
    cout<<fib_optimal(n)<<endl;
    return 0;
}