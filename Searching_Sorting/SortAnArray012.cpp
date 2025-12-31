#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& nums){//Counting Method ... O(n) ... double pass
    int n =nums.size();
    int count0 =0;
    int count1 =0;
    int count2 =0;
    for(int i =0 ; i<n ; i++){
        if(nums[i]==0) count0++;
        if(nums[i]==1) count1++;
        if(nums[i]==2) count2++;
    }
    int index =0;
    while(count0--) nums[index++]=0;
    while(count1--) nums[index++]=1;
    while(count2--) nums[index++]=2;
}

void DutchNationalFlag(vector<int>& nums){//O(n) ... single pass 
    int low =0  , mid =0 ,high = nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        if(nums[mid]==1){
            mid++;
        }
        if(nums[mid]==2){
            swap(nums[high],nums[mid]);
            high--;
        }
    }
}

int main(){
    vector<int> vec = {0,1,2,2,2,1,1,0,0};
    DutchNationalFlag(vec);
    for(int i = 0 ;i <vec.size() ; i++){
        cout<<vec[i];
        cout<<" ";
    }
}