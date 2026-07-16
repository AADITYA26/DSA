#include <bits/stdc++.h>
using namespace std;
int n;
int buy_sell_stock(int index , bool buy , vector<int>& stocks,vector<vector<int>> &dp){
    if(index >= n ) return 0;
    if(dp[index][buy]!=-1)return dp[index][buy];
    if(buy){
        int bought  =  buy_sell_stock(index +1 , false , stocks,dp) - stocks[index];
        int notbought = buy_sell_stock(index +1 , true , stocks,dp);
        return dp[index][buy] = max(bought , notbought);
    }
    else{
        int sell = buy_sell_stock(index+1 , true , stocks,dp) + stocks[index];
        int notsell = buy_sell_stock(index+1,false , stocks,dp);
        return dp[index][buy] = max(sell,notsell);
    }
}



int tabulation(vector<int> stocks){
    n = stocks.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i = n-1 ; i >=0 ; i--){
        for(int j = 0 ; j < 2 ; j++){
            if(j){
                    int bought  =  dp[i+1][0]- stocks[i];
                    int notbought = dp[i+1][1];
                    dp[i][j] = max(bought , notbought);
                }
            else{
                int sell = dp[i+1][1] + stocks[i];
                int notsell = dp[i+1][0];
                dp[i][j] = max(sell,notsell);
            }
            }
        }
    return dp[0][1];
}

int optimal(vector<int>& stocks){
    n = stocks.size();
    vector<int> prev(2,0);
    for(int i = n-1 ; i >= 0 ; i--){
        vector<int> curr(2,0);
        for(int j = 0 ; j < 2 ; j++){
            if(j){
                int buy = prev[0]-stocks[i];
                int notbuy = prev[1];
                curr[j] = max(buy,notbuy);
            }
            else{
                int sell = prev[1]+stocks[i];
                int notsell = prev[0];
                curr[j] = max(sell,notsell);
            }
        }
        prev = curr;
    }
    return prev[1];
}

int main() {
    vector<int> stocks = {7, 1, 5, 3, 6, 4};
    n = stocks.size();
    vector<vector<int>> dp(n , vector<int>(2,-1));
    cout<<optimal(stocks);
    return 0;
}