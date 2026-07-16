#include <bits/stdc++.h>
using namespace std;
int n;
int buy_sell_stock5(vector<int> &stocks , int index , bool buy){
    if(index >= n)return 0;
    if(buy){
        int bought = buy_sell_stock5(stocks , index +1 , false) - stocks[index];
        int notbought = buy_sell_stock5(stocks , index +1 , true) ;
        return max(bought , notbought);
    }
    else{
        int sell =  buy_sell_stock5(stocks,index+2,true) + stocks[index];
        int notsell = buy_sell_stock5(stocks , index+1, false);
        return max(sell,notsell);
    }
}

int tabulation(vector<int> stocks){
    n = stocks.size();
    vector<vector<int>> dp(n+2 , vector<int>(2,0));
    for(int i = n-1 ; i>= 0 ; i--){
        for(int j = 0 ; j < 2 ; j++){
            if(j){
                int bought = dp[i+1][0] - stocks[i];
                int notbought = dp[i+1][1] ;
                dp[i][ j] = max(bought, notbought);
            }
            else{
                int sell = dp[i+2][1] + stocks[i];
                int notsell = dp[i+1][0];
                dp[i][j] =  max(notsell,sell);
            }
        }
    }
    return dp[0][1];
}

int optimal(vector<int>& stocks){
    n = stocks.size();
    vector<int> ahead2(2,0);
    vector<int> ahead1(2,0);
    for(int i = n-1 ; i>= 0 ; i--){
        vector<int> curr(2,0);
        for(int j = 0 ; j < 2 ; j++){
            if(j){
                int bought = ahead1[0] - stocks[i];
                int notbought = ahead1[1] ;
                curr[j] = max(bought, notbought);
            }
            else{
                int sell = ahead2[1] + stocks[i];
                int notsell = ahead1[0];
                curr[j] =  max(notsell,sell);
            }
        }
        ahead2 = ahead1;
        ahead1 = curr;
    }
    return ahead1[1];
}
//Dp on stocks 6 entirely same to 2 so skipping it 
int main() {
    
    return 0;
}