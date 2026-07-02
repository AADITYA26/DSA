#include <bits/stdc++.h>
using namespace std;

int MaxSubElementSum(vector<int> &nums ,int idx){
    if(idx == 0)return max(0,nums[idx]);
    if(idx<0) return 0;
    int pick = nums[idx]+MaxSubElementSum(nums , idx-2);
    int notpick = MaxSubElementSum(nums,idx-1);
    return max(pick,notpick);
}

int MaxSubElementSum_memoization(vector<int> &nums , int idx  , vector<int>&dp){
    if(idx == 0)return dp[0] = max(0,nums[idx]);
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int pick = nums[idx]+MaxSubElementSum(nums , idx-2);
    int notpick = MaxSubElementSum(nums,idx-1);
    return dp[idx] = max(pick,notpick);
}

int MaxSubElementSum_tabulization(vector<int> &nums){
    if(nums.size()==1 ) return max(0,nums[0]);
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    dp[1] = max(dp[0],nums[1]);
    for(int i = 2 ; i <n ; i++){
        dp[i] = max (dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}


int MaxSubElementSum_optimal(vector<int> &nums){
    if(nums.size()==1 ) return max(0,nums[0]);
    int n = nums.size();
    int prev2 = nums[0];
    int prev1 = max(prev2,nums[1]);
    int ans = 0 ;
    for(int i = 2 ; i <n ; i++){
        ans = max(prev1,prev2+nums[i]);
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}



int main() {
    vector<int> nums = {2,1,3,9,3,5};
    vector<int> dp(nums.size(),-1);
    cout<<MaxSubElementSum_optimal(nums);
    return 0;
}