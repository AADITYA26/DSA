#include <iostream>
#include <vector>
using namespace std;

int BinarySearch_Recursion(vector<int>& nums , int val , int start , int end){//For sorted Arrays only
    int mid =(start+end)/2;
    if(val>nums[mid]) return BinarySearch_Recursion(nums,val,mid+1,end);
    else if(val<nums[mid]) return BinarySearch_Recursion(nums,val,start,mid-1); 
    else if(val == nums[mid]) return mid;
    return -1;
}
//For rotated sorted arrays
int Search(vector<int> nums , int val){//using Binary Search algos , modified Binary Search
    int start= 0 ;
    int end =nums.size()-1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(val == nums[mid])return mid;
        if(nums[0]<nums[mid]){//Left Sorted 
            if(nums[start]<=val&&nums[mid]>=val){//Checking if value on right side 
                end = mid -1;
            }
            else start =mid;//if Value not found on right then moving to left
        }
        else {//Right Sorted
                if(nums[mid]<=val&&nums[end]>=val){//Checking if value is in right side
                start = mid +1;
            }
            else end =mid-1;//val not found on right side now will search on left
        }
    }
    return -1;
}

int main(){
    vector<int> vec = {7,8,1,2,3,4,5,6};
    int index = Search(vec , 2);
    cout<<index<<endl;
}