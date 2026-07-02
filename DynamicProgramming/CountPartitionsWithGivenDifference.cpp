#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> & nums , int k){
    int n = nums.size();
    vector<int> prev(k+1,0);
    if(nums[0]<=k&&nums[0]!=0)
    prev[nums[0]] = 1;
    if(nums[0]==0)prev[0]=2;
    else prev[0]=1;
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

int countPartitions(vector<int> & nums , int D){
    int sum = 0;
    for(auto it : nums)sum+=it;
    int toFind = (sum-D)/2;
    return optimal(nums,toFind);
}

int main() {
    
    return 0;
}

