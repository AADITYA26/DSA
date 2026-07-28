#include <bits/stdc++.h>
using namespace std;
int n;
int recursive(vector<int>&nums , int index , int prev_index){
    if(index >= n ) return 0;
    if(prev_index ==-1 || nums[index]%nums[prev_index]==0){
        int take = 1 +  recursive(nums , index +1 , index);
        int nottake = recursive(nums , index+1 , prev_index);
        return max(take,nottake);
    }
    else{
        return recursive(nums,index+1,prev_index);
    }
}

int tabulation(vector<int> nums){
    n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = n-1 ; i >= 0 ; i--){
        for(int prev = i-1 ; prev >= -1 ; prev--){
            if(prev==-1 || nums[i]%nums[prev]==0){
                int take = dp[i+1][i+1]+1;
                int nottake = dp[i+1][prev+1];
                dp[i][prev+1] = max(take,nottake);
            }
            else dp[i][prev+1] = dp[i+1][prev+1];
        }
    }
    return dp[0][0];
}

int main() {
    vector<int> nums = {8,1,2,4};
    cout<<tabulation(nums);
    return 0;
}