#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPerms(vector<int>& nums, int index,vector<vector<int>>&ans){//O(n!*n) time complexity
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index ; i <nums.size() ; i++){//loop should be from index to end as the prioir combinations are already covered
        swap(nums[i],nums[index]);//index swapped with element at i
        getPerms(nums,index+1,ans);
        swap(nums[i],nums[index]);//backtracking
    }
}

vector<vector<int>> permutations(vector<int>& nums){
    vector<vector<int>> ans;
    getPerms(nums , 0 , ans);
    return ans;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permutations(nums);
    for(vector<int> element : ans){
        for(int j = 0 ; j<element.size() ; j++){
            cout<<element[j]<<" ";
        }
        cout<<endl;
    }
}