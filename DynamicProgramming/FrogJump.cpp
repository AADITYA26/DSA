#include <bits/stdc++.h>
using namespace std;

int FrogJump(int n  , vector<int>&Height){
    if(n==0) return 0;
    int left = FrogJump(n-1,Height)+abs(Height[n]-Height[n-1]);
    int right = INT_MAX;
    if(n>1){
        int right = FrogJump(n-2,Height)+abs(Height[n]-Height[n-2]);
    }
    return min(left,right);
}

int FrogJump_Memoization(int n , vector<int> & Height , vector<int>& dp){
    if(n==0) return dp[0]=0;
    if(dp[n]!=-1) return dp[n];
    int left = FrogJump_Memoization(n-1,Height,dp)+abs(Height[n]-Height[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = FrogJump_Memoization(n-2,Height,dp)+abs(Height[n]-Height[n-2]);
    }
    return dp[n] = min(left,right);
}

int Frog_Jump_optimal(int n , vector<int> Height){
    if(n==0) return 0;
    int prev = 0 , prev2 = 0;
    int curr = 0;
    for(int i = 1 ; i <= n ; i ++){
        int left = prev + abs(Height[i]-Height[i-1]);
        int right = INT_MAX;
        if(i>1){
            right  = prev2 + abs(Height[i]-Height[i-2]);
        }
        curr = min(left,right);
        prev2 = prev;
            prev = curr;
    }
    return curr;
}
//k JUMPS
int Frog_Jump_optimal(int n , vector<int> Height , int k){
    if(n==0) return 0;
    vector<int> prev(k,0);
    int curr = 0;
    for(int i = 1 ; i <= n ; i ++){
        curr = 0;
        for(int j = 0 ; j < k ; j ++){
            if(i>j){
                curr = min (curr , prev[j]+abs(Height[i]-Height[i-j-1]));
            }
        }
        for(int i = k-1 ; i > 0 ; i++ ){
            prev[i] = prev[i-1];
        }
        prev[0] = curr;
    }
    return curr;
}

int FrogJumpkSteps_memoization(int n , vector<int> & Height , int k){
    if(n==0) return 0;
    vector<int> dp(n+1,0);
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < k ; j++){
            if(i>j){
                dp[i] = dp[i-j-1] + abs(Height[i]-Height[i-j-1]);
            }
        }
    }
    return dp[n];
}

int main() {
    
    return 0;
}