#include <bits/stdc++.h>
using namespace std;

int Count(vector<int>&nums , int k , int index){
    if(k == 0) return 1;
    if(index == 0)return nums[0] ==  k;
    int notpick = Count(nums,k,index-1);
    int pick = 0;
    if(nums[index]<k)pick = Count(nums,k-nums[index],index-1);
    return pick+notpick;
}

int tabulation(vector<int> & nums , int k){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1 , 0));
    if(nums[0]<=k)
    dp[0][nums[0]] = 1;
    for(int i = 0 ; i < n ; i++)dp[i][0] = 1;
    for(int index = 1 ; index < n ; index++){
        for(int target = 0 ; target < k+1 ; target++){
            int notpick = dp[index-1][target];
            int pick = 0;
            if(nums[index]<=target)pick = dp[index-1][target-nums[index]];
            dp[index][target] = pick+notpick;
        }
    }
    return dp[n-1][k];
}

int optimal(vector<int> & nums , int k){
    int n = nums.size();
    vector<int> prev(k+1,0);
    if(nums[0]<=k)
    prev[nums[0]] = 1;
    prev[0] = 1;
    for(int index = 1 ; index < n ; index++){
        vector<int> curr(k+1,0);
        curr[0] = true;
        for(int target = 0 ; target < k+1 ; target++){
            int notpick = prev[target];
            int pick = 0;
            if(nums[index]<=target)pick = prev[target-nums[index]];
            curr[target] = pick+notpick;
        }
        prev = curr;
    }
    return prev[k];
}

int main() {
    vector<int> nums = {1,2,3};
    cout<<optimal(nums,3)<<endl;
    return 0;
}