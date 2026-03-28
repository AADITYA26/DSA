#include <bits/stdc++.h>
using namespace std;

vector<int> calaculateStockSpan(vector<int> StockPrices){
    vector<int> ans;
    stack<int> temp;
    temp.push(0);
    ans.push_back(1);
    if(StockPrices.size()==1){//in case only one day stock entered
        return ans;
    }
    for(int i = 1 ; i<StockPrices.size() ; i++){
            while(!temp.empty()&&StockPrices[i]>=StockPrices[temp.top()]){
                temp.pop();
            }
            if(temp.empty())ans.push_back(i+1);
            else ans.push_back(i-temp.top());
            temp.push(i);//storing for finding the previous highs of the array elements
    }
    return ans;
}

int main(){
    vector<int> StockPrices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = calaculateStockSpan(StockPrices);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}