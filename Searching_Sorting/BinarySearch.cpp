#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>& nums , int val){
    int n = nums.size();
    int left = 0;
    int right = n-1;
    while(left <= right){
        //int mid = (left+right)/2; 
        //the above formula would fail if both start and end are int max
        int mid = left +(right-left)/2;
        if(nums[mid]==val)return mid;
        else if(val<nums[mid])right = mid-1;
        else if(val>nums[mid])left = mid+1;
    }
    return -1;
}

int BinarySearch_Recursion(vector<int>& nums , int val , int start , int end){
    int mid =(start+end)/2;
    if(val>nums[mid]) return BinarySearch_Recursion(nums,val,mid+1,end);
    else if(val<nums[mid]) return BinarySearch_Recursion(nums,val,start,mid-1); 
    else if(val == nums[mid]) return mid;
    return -1;
}

int main(){
    vector<int> vec = {1,2,3,4,5,6};
    int index = BinarySearch(vec , 6);
    int index2 = BinarySearch_Recursion(vec , 4 , 0 , vec.size()-1);
    cout<<index2<<endl;
    cout<<index<<endl;
}