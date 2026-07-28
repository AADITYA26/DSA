#include <bits/stdc++.h>
using namespace std;
int n;
int LongestIncreasingSub(vector<int> & nums , int index , int prev_index){
    if(index >= n )return 0;
    if(prev_index == -1 || nums[index]>nums[prev_index]){
    int take = 1 + LongestIncreasingSub(nums , index + 1,index);
    int nottake = LongestIncreasingSub(nums,index+1,prev_index);
    return max(take,nottake);
    }
    else return LongestIncreasingSub(nums , index+1 , prev_index);
}

int memoize(const vector<int> & nums , int index , int prev_index , vector<vector<int>>&dp){
    if(index >= n )return 0;
    if(dp[index][prev_index+1]!=-1)return dp[index][prev_index+1];
    if(prev_index == -1 || nums[index]>nums[prev_index]){
        int take = 1 + memoize(nums,index+1,index,dp);
        int nottake = memoize(nums,index+1,prev_index,dp);
        return dp[index][prev_index+1] = max(take,nottake);
    }
    else return dp[index][prev_index+1] = memoize(nums,index+1,prev_index,dp);
}

int tabulation(vector<int> & nums){
    n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int index = n-1 ; index >=0 ; index--){
        for(int prev_index = n-1 ; prev_index >=-1; prev_index-- ){
            if(prev_index == -1 || nums[index]>nums[prev_index]){
                int take = 1 + dp[index+1][index+1];
                int nottake = dp[index+1][prev_index+1];
                dp[index][prev_index+1] = max(take,nottake);
            }
            else dp[index][prev_index+1] = dp[index+1][prev_index+1];
        }
    }
    return dp[0][0];
}

int optimal(vector<int> & nums){
    n = nums.size();
    vector<int> prev(n+1,0);
    for(int index = n-1 ; index >= 0 ; index --){
        vector<int> curr(n+1,0);
        for(int prev_index = index-1 ; prev_index>=-1 ; prev_index--){
            if(prev_index==-1||nums[index]>nums[prev_index]){
                int take = 1 + prev[index+1];
                int nottake = prev[prev_index+1];
                curr[prev_index+1] = max(take,nottake);
            }
            else curr[prev_index+1] = prev[prev_index+1];
        }
        prev = curr;
    }
    return prev[0];
}

int best(vector<int> nums){
    vector<int> dp(n,1);
    int maxi = -1e9;
    for(int i = 0 ; i < n ; i++){
        for(int prev = 0 ; prev < i ; prev ++){
            if(nums[i] > nums[prev]){
                dp[i] = max(dp[prev]+1,dp[i]);
            } 
        }
        maxi = max(dp[i],maxi);
    }
    return maxi;
}

void print_lis(vector<int> nums){
    n = nums.size();
    vector<int> dp(n,1) , hash(n);
    for(int i =0 ; i < n ; i++ )hash[i] = i;
    int maxi = 1;
    int lastindex = 0;
    for(int i = 0 ; i < n ; i++){
        for(int prev = 0 ; prev < i ; prev ++){
            if(nums[i] > nums[prev]&&dp[prev]+1>dp[i]){
                dp[i] = max(dp[prev]+1,dp[i]);
                hash[i] = prev;
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
            lastindex = i;
        }
    }
    while(hash[lastindex]!=lastindex){
        cout<<nums[lastindex]<<" ";
        lastindex = hash[lastindex];
    }
    cout<<nums[lastindex]<<endl;

}

int binarySearch(vector<int> nums){
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }else{
            int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind] = nums[i];
        }
    }
    return temp.size();
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    cout<<binarySearch(nums);
    return 0;
}