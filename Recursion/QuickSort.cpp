#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& nums , int start , int end){
    int pivot = nums[end];
    int index = start-1;
    for(int i =start ; i < end ; i++ ){
        if(nums[i]<=pivot){
            index ++;
            swap(nums[index],nums[i]);
        }
    }
    index++;
    swap(nums[index],nums[end]);
    return index;
}

void helper(vector<int> &nums , int start , int end){
    if(start>=end) return;
    int pivot = partition(nums, start ,end);
    helper(nums , start , pivot-1);
    helper(nums, pivot +1 , end);    
}

void QuickSort(vector<int>& nums){
    helper(nums,0,nums.size()-1);
}

int main(){
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    QuickSort(nums);
    for(auto i : nums){
        cout<<i<<" ";
    }
}