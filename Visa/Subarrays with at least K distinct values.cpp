#include <bits/stdc++.h>
using namespace std;

long long count(vector<int>  nums , int k){
    unordered_map<int , int> mp;
    int n = nums.size();
    long long ans = 0 ;
    int left = 0 ;
    int right = 0 ;
    k--;
    while(right < nums.size()){
        mp[nums[right]]++;
        while(mp.size() > k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0)mp.erase(nums[left]);
            left++;
        }
        ans+=left;
        right++;
    }
    ans = 1LL *(n)*(n+1)/2 - ans;
    return ans;
}


int main() {
    
    return 0;
}