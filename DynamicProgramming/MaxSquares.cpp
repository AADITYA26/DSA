#include <bits/stdc++.h>
using namespace std;

int maxSquares(vector<vector<int>> nums){
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int sum = 0 ;
    for(int i = 0 ; i < m ; i++){
        dp[0][i] = nums[0][i];
        sum+=dp[0][i];
    }
    for(int i = 1 ; i < n ; i++){
        dp[i][0] = nums[i][0];
        sum+=dp[i][0];
    }
    for(int i = 1; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(nums[i][j]==0){
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            sum+=dp[i][j];
        }
    }
    return sum;
}

int main() {
    vector<vector<int>> mat = {
    {1,0,1},
    {1,1,0},
    {1,1,0}
};
cout<<maxSquares(mat);
    return 0;
}