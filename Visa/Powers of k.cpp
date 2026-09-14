#include <bits/stdc++.h>
using namespace std;

int powers(vector<int> nums , int k){
    if(k==1){
        return count(nums.begin() , nums.end() , 1);
    }
    sort(nums.begin() , nums.end());
    long long curr = 1;
    int ans = 0;
    for(int i = 0 ; i < nums.size() ; i ++){
        if(nums[i]==curr){
            ans++;
            continue;
        }
        else if(nums[i] > curr){
            curr = curr*k;
            i=i-1;
        }
    }
    return ans;
}


int main() {
    
    return 0;
}