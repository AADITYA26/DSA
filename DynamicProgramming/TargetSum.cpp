#include <bits/stdc++.h>
using namespace std;

int targetSum(vector<int>& nums , int index , int target){
    if(index == 0 ){
        if(nums[0]==0)return 2;
        if(target + nums[0] == 0||target-nums[0]==0) return 1;
        else return 0;
    }
    int plus = targetSum(nums , index -1 ,target - nums[index]);
    int minus = targetSum(nums , index -1 , target + nums[index]);
    return plus + minus;
}

//you can do it with count partitions with difference d because anyways you can do it with plus and minus assignment



int main() {
    vector<int> nums = {1,2,3,1};
    cout<<targetSum(nums,3,3);
    return 0;
}