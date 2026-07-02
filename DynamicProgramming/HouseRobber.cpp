#include <bits/stdc++.h>
using namespace std;


int houseRobber(vector<int>& nums){
    int n  = nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    if(n==3)return max(nums[0],max(nums[1],nums[2]));
    int prev2 = nums[0];
    int prev1 = max(prev2,nums[1]);
    //Excluding last
    int excludinglast = 0;
    for(int i = 2 ; i < n-1 ; i++ ){
        excludinglast = max(prev1 , nums[i]+prev2);
        prev2 = prev1;
        prev1 = excludinglast;
    }
    prev2 = nums[1];
    prev1 = max(prev2,nums[2]);
    int excludingfirst = 0;
    for(int i = 3 ; i < n ; i++ ){
        excludingfirst = max(prev1 , nums[i]+prev2);
        prev2 = prev1;
        prev1 = excludingfirst;
    }
    return max(excludingfirst,excludinglast);
}

int main() {
    
    return 0;
}