#include <bits/stdc++.h>
using namespace std;
int n;
int buy_sell_stock3(vector<int> &stocks , int buy , int index , int left){
    if(index >= n || left <= 0) return 0;
    if(buy){
        int bought = buy_sell_stock3(stocks , false , index+1 , left)-stocks[index];
        int notbought = buy_sell_stock3(stocks,true,index+1,left);
        return max(bought,notbought);
    }
    else{
        int sell = buy_sell_stock3(stocks, true , index +1 , left-1)+stocks[index];
        int notsell = buy_sell_stock3(stocks , false , index +1,left);
        return max(sell,notsell);
    }
}

int tabulation(vector<int> & stocks){
    n = stocks.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j < 2 ; j++ ){
            for(int left = 1 ; left <3 ; left ++){
                if(j){
                    int bought = dp[i+1][0][left]-stocks[i];
                    int notbought = dp[i+1][1][left];
                    dp[i][j][left] = max(bought,notbought);
                }
                else{
                    int sell = dp[i+1][1][left-1]+stocks[i];
                    int notsell = dp[i+1][0][left];
                    dp[i][j][left] =  max(sell,notsell);
                }
            }
        }
    }
    return dp[0][1][2];
}


int optimal(vector<int> & stocks){
    n = stocks.size();
    vector<vector<int>> prev(2,vector<int>(3,0));
    for(int i  = n-1 ; i >= 0 ; i--){
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int j = 0 ; j < 2 ; j++){
            for(int left = 1 ; left < 3 ; left ++){
                if(j){
                    int bought = prev[0][left] - stocks[i];
                    int notbought = prev[1][left];
                    curr[j][left] = max(bought,notbought);
                }
                else{
                    int sell = prev[1][left-1]+stocks[i];
                    int notsell =prev[0][left];
                    curr[j][left] = max(sell,notsell);
                }
            }
        }
        prev = curr;
    }
    return prev[1][2];
}
int main() {
    vector<int> stocks = {3, 3, 5, 0, 0, 3, 1, 4};
    n = stocks.size();
    cout<<optimal(stocks);
    return 0;
}