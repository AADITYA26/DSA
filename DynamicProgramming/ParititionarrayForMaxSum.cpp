#include <bits/stdc++.h>
using namespace std;

int maxsum(vector<int> nums , int i , int n , int k){
    if(i==n) return 0;
    int total = 0;
    int max_ele = 0;
    for(int j = i ; j < min(n,i+k) ; j++){
        max_ele = max(max_ele , nums[j]);
        total = max(total ,(j-i+1)*max_ele+maxsum(nums,j+1,n,k));
    }
    return total;
}

int tab(vector<int> nums , int k){
    int n = nums.size();
    vector<int> dp(n+1,0);
    for(int i = n-1 ; i >= 0 ; i--){
        int total = 0;
        int max_ele = 0;
        for(int j = i ; j < min(n,i+k) ; j++){
            max_ele = max(max_ele , nums[j]);
            total = max(total ,(j-i+1)*max_ele+dp[j+1]);
        }
        dp[i] = total;
    }
    return dp[0];
}



int main() {
    vector<int> nums = {1,2,3,15};
    cout<<tab(nums,4);
    return 0;
}