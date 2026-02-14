#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>&nums , int start , int mid ,int end){
    int i = start , j =mid+1;
    vector<int> n ;
    int Inversions =0 ;
    for(;i<=mid&&j<=end;){
        if(nums[i]>nums[j]){
            Inversions  += mid-i+1;
            n.push_back(nums[j]);
            j++;
        }
        else{
            n.push_back(nums[i]);
            i++;
        }
    }
    for(;i<=mid;i++){
        n.push_back(nums[i]);
    }
    for(;j<=end;j++){
        n.push_back(nums[j]);
    }
    for(int i = 0 ; i <n.size() ; i++){
        nums[start+i] = n[i];
    }
    return Inversions;
}


void mergeSort(vector<int> &nums , int start , int end , int &Inversions){
    if((end-start+1)<=1){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(nums,start,mid , Inversions);
    mergeSort(nums,mid+1,end , Inversions);
    Inversions += merge(nums,start,mid,end);
}

int CountInversions_Bruteforce(vector<int>& nums){
    int count =0;
    for(int i = 0 ; i <nums.size() ; i++){
        for(int j = i +1 ; j <nums.size() ; j++){
            if(nums[i]>nums[j]) count ++;
        }
    }
    return count;
}

int CountInversions_Optimal(vector<int> nums){
    int Inv = 0;
    mergeSort(nums ,0 ,nums.size()-1,Inv );
    return Inv;
}

int main(){
    vector<int> arr = {6,3,5,2,7};
    int ans = CountInversions_Optimal(arr);
    cout<<ans<<" ";
}