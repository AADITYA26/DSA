#include <bits/stdc++.h>
using namespace std;

int maxconsectiveones(vector<int> nums , int k){
    int n = nums.size();
    int left = 0 ;
    int right = 0 ;
    int length = 0;
    int zeroes = 0;
    int maxLength = 0;
    while(right<n){
        if(nums[right]==0){
            zeroes++;
            if(zeroes>k){
                while(zeroes>k&&left<=right){;
                    if(nums[left]==0)zeroes--;
                    left++;
                }
            }
        }
        length = right - left +1;
        right++;
        maxLength = max(length,maxLength);
    }
    return maxLength;
}


int main() {
    vector<int> nums = {1,1,1,0,0,1,1,1,0};
    cout<<maxconsectiveones(nums,2);
    return 0;
}