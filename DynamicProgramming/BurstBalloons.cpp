#include <bits/stdc++.h>
using namespace std;

int burstballoons(vector<int>& balloon , int i , int j){
    if(i>j)return 0;
    int maxi = INT_MIN;
    for(int  k =i ; k <= j ; k++){
        int cost = balloon[i-1]*balloon[k]*balloon[j+1]+burstballoons(balloon,i,k-1)+burstballoons(balloon,k+1,j);
        maxi = max(maxi,cost);
    }
    return maxi;
}

int tab(vector<int> & balloon){
    int n = balloon.size();
    balloon.insert(balloon.begin(),1);
    balloon.push_back(1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i = n ; i > 0 ; i --){
        for(int j = i ; j <= n ; j ++){
            int maxi = -1e9;
            for(int  k =i ; k <= j ; k++){
                int cost = balloon[i-1]*balloon[k]*balloon[j+1]+dp[i][k-1]+dp[k+1][j];
                maxi = max(maxi,cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main() {
    vector<int> nums = {3,1,5,8};
    cout<<tab(nums);
    return 0;
}