#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums ,int start ,int mid , int end){
    vector<int> n ;
    int i =start , j = mid+1;
    for( ; i <= mid && j <=end ;){
        if(nums[i]>nums[j]){
            n.push_back(nums[j]);
            j++;
        }
        else {
            n.push_back(nums[i]);
            i++;
        }
    }
    for( ; i <=mid ; i++){
        n.push_back(nums[i]);
    }
    for( ; j<=end ; j++){
        n.push_back(nums[j]);
    }
    for(int i = 0 ; i<n.size() ; i ++){
        nums[start+i] = n[i]; 
    }
}

void mergeSort(vector<int> &nums , int start , int end){
    if((end - start+1)<=1){
        return;
    }
    int mid = (start +end)/2;
    mergeSort(nums,start ,mid);
    mergeSort(nums,mid+1,end);
    merge(nums , start ,mid ,end);
}

int main(){
    vector<int> nums = {5,8,9,4,2,6,1,0};
    mergeSort(nums,0,7);
    for(auto x : nums){
        cout<<x<<" ";
    }
}