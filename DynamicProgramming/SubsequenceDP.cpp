#include <bits/stdc++.h>
using namespace std;

bool Subsequence(vector<int>& nums , int target , int index){
    if(target==0)return true;
    if(index == 0) return (nums[0]==target);
    
    bool nottake = Subsequence(nums,target,index-1);
    bool take = false;
    if(target >= nums[index]){
        take =  Subsequence(nums,target-nums[index],index-1);
    }
    return nottake||take;
}

bool Subssequence_memoization(vector<int> & nums , int target , int index,vector<vector<int>> dp){
    if(target==0)return true;
    if(index == 0) return (nums[0]==target);
    if(dp[index][target]!=-1)return dp[index][target];
    bool nottake = Subssequence_memoization(nums,target,index-1,dp);
    bool take = false;
    if(target >= nums[index]){
        take =  Subssequence_memoization(nums,target-nums[index],index-1,dp);
    }
    return dp[index][target]=nottake||take;
}

bool tabulation(vector<int> & nums , int k){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i = 0;i< n-1 ; i++)
    dp[i][0] = true;
    dp[0][nums[0]] = true;
    for(int index = 0 ; index < n-1 ; index++){
        for(int target = 0 ; target <k+1 ; target ++ ){
            bool nottake = dp[index-1][target];
            bool take = false;
            if(target >= nums[index]){
                take = dp[index-1][target];
            }
            dp[index][target]=nottake||take;
        }
    }
    return dp[n][k];
}

bool optimal(vector<int> & nums , int k){
    int n = nums.size();
    vector<int> prev(k+1,false);
    prev[0] = true;
    if(nums[0]<=k)
    prev[nums[0]] = true;
    for(int index = 1 ; index < n ; index++){
        vector<int> curr(k+1,false) ;
        curr[0] = true;
        for(int target = 0 ; target <k+1 ; target ++ ){
            bool nottake = prev[target];
            bool take = false;
            if(target >= nums[index]){
                take = prev[target-nums[index]];
            }
            curr[target]=nottake||take;
        }
        prev = curr;
    }
    return prev[k];
}

int main() {
    
    return 0;
}