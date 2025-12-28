#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
    public:
        static int buy_sell_stock(vector<int>& stocks){
            int bestbuy = stocks.at(0);
            int maxProfit = 0;
            for(int i= 0 ; i<stocks.size();i++){
                if(stocks.at(i)>bestbuy){
                    maxProfit = max(maxProfit,stocks.at(i)-bestbuy);
                }
                bestbuy = min(bestbuy,stocks.at(i));
            }
        return maxProfit;
        }
};

int main(){
        vector<int> stocks = {7,2,7,1,8};
        Solution a;
        cout<<a.buy_sell_stock(stocks)<<endl;
}