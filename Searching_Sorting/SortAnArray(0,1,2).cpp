#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& nums){//Method ... O(n)
    int n =nums.size();
    int count0 =0;
    int count1 =0;
    int count2 =0;
    for(int i =0 ; i<n ; i++){
        if(nums[i]==0) count0++;
        if(nums[i]==1) count1++;
        if(nums[i]==2) count2++;
    }
    for(int i = 0 ; i<count0;i++) nums[i]=0;
    for(int i = 0 ; i<count1;i++) nums[i]=1;
    for(int i = 0 ; i<count2;i++) nums[i]=2;
}

int main(){
    vector<int> vec = {0,1,2,2,2,1,1,0,0};
    Sort(vec);
    for(int i = 0 ;i <5 ; i++){
        cout<<vec[i];
        cout<<" ";
    }
}