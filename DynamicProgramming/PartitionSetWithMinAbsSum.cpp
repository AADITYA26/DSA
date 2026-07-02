#include <bits/stdc++.h>
using namespace std;

int minAbsSum(vector<int> & nums){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n ; i++)sum+=nums[i];
    vector<int> prev(sum+1,0);
    prev[0] = true;
    prev[nums[0]] = true;
    for(int index = 1 ; index < n ; index++){
        vector<int> curr(sum+1 , 0);
        curr[0] = true;
        for(int target = 0; target < sum+1 ; target++){
            bool notPick = prev[target];
            bool pick = false;
            if(nums[index]<=target){
                pick = prev[target-nums[index]];
            }
            curr[target] = pick||notPick;
        }
        prev = curr;
    }
    int Min = 1e9;
    for(int i = 0; i <= sum/2 ; i++){
        if(!prev[i])continue;
        Min = min(Min , abs(2*i-sum));
    }
    return Min;
}

int main() {
    vector<int> nums = {3,2,7};
    cout<<minAbsSum(nums)<<endl;
    return 0;
}