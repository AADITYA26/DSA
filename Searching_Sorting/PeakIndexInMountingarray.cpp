#include <iostream>
#include <vector>
using namespace std;

int PeakIndex(vector<int>& nums){
    int st=1;
    int end=nums.size()-2;
    while(st<end){
        int mid = st + (end-st)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;//return if mid is the peak
        else if(nums[mid-1]<=nums[mid])st =mid+1;//mid on the upward slope peak on the right 
        else end=mid-1;//mid on the downward slope peak on the left
    }
    cout<<"NO PEAK ELEMENT FOUND"<<endl;
    return -1;
}

int PeakIndex_optimized(vector<int>& nums){
    int st = 0, end = nums.size() - 1;
    while (st < end) {
        int mid = st + (end - st) / 2;
        if (nums[mid] < nums[mid + 1]) st = mid + 1;//mid on the upward slope
        else end = mid;//mid on the downward slope
}
    return st; // st will land on the peak
}

int main(){
    vector<int> vec = {0,3,7,8,9,5,2};
    int x = PeakIndex(vec);
    cout<<x<<endl;
}