#include <bits/stdc++.h>
using namespace std;


int MinNumCoins(vector<int> &coins , int value , int index){
    if(value == 0)return 0;
    if(index == 0){
        if(value%coins[0]==0)return value/coins[0];
        else return 1e9;
    }
    int notpick = MinNumCoins(coins , value , index-1);
    int pick = 1e9;
    if(coins[index]<=value) pick = 1 + MinNumCoins(coins,value-coins[index],index);
    return min(notpick , pick);
}

int memoization(vector<int> &coins , int value , int index , vector<vector<int>>& dp){
    if(value == 0)return 0;
    if(value%coins[0]==0)return value/coins[0];
    else return 1e9;
    if(dp[index][value] != -1)return dp[index][value];
    int notpick = memoization(coins , value , index-1,dp);
    int pick = 1e9;
    if(coins[index]<=value) pick = 1 + memoization(coins,value-coins[index],index,dp);
    return dp[index][value] = min(notpick , pick);
}

int tabulation(vector<int> & coins , int value){
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(value+1,0));
    for(int i = 0; i < n ; i++) dp[i][0] = 0;
    for(int cap = 0 ; cap <= value ; cap++){
        if (cap % coins[0] == 0)dp[0][cap] = cap / coins[0];
        else dp[0][cap] = 1e9;
    }
    for(int index = 1 ; index < n ; index++){
        for(int k = 0 ; k < value+1 ; k++ ){
            int notpick = dp[index-1][k];
            int pick = 1e9;
            if(coins[index]<=k) pick = 1 + dp[index][k-coins[index]];
            dp[index][k] = min(notpick , pick);
        }
    }
    return dp[n-1][value];
}

int optimal(vector<int> & coins , int value){
    int n= coins.size();
    vector<int> prev(value+1 , 0);
    prev[0] = 0;
    for(int cap = 0; cap < value+1 ; cap++){
        if(cap%coins[0]==0)prev[cap] = cap/coins[0];
        else prev[cap] = 1e9;
    }
    for(int index = 1 ; index < n ; index ++){
        vector<int> curr(value+1,0);
        curr[0] = 0;
        for(int cap = 0 ; cap < value+1 ;cap++){
            int notpick = prev[cap];
            int pick = 1e9;
            if(coins[index]<=cap)pick = 1+curr[cap-coins[index]];
            curr[cap] = min(notpick,pick);
        }
        prev = curr;
    }
    return prev[value];
}
int main() {
    vector<int> coins = {9,6,5,1};
    cout<<optimal(coins,11);
    return 0;
}