#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> stocks){
    int profit  = 0;
    int mini = stocks[0];
    for(int i = 1 ; i< stocks.size() ; i++){
        int cost = stocks[i] - mini;
        profit  = max (profit , cost);
        mini = min(mini,stocks[i]);
    }
    return profit;
}

int main() {
    cout<<solution({7,6,1,5,8});

    return 0;
}