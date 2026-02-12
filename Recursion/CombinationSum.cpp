#include <bits/stdc++.h>
using namespace std;

//Bruteforce Approach
void helper(vector<int> &nums , vector<vector<int>> &ans  , vector<int> &curr , int target, int index){//Recursive Way
    int n  = nums.size();
    if(index == n){ return;}
    if(target==0){
        ans.push_back(curr);
        return;
    }
    else if (target<0){
        return;
    }
    else {
        curr.push_back(nums[index]);//if including the number at the index
        helper(nums,ans,curr,target-nums[index],index);//for multiple inclusion and ingle inclusion both cases
        curr.pop_back();
        helper(nums,ans,curr,target,index+1);//for not including case
    }
}

vector<vector<int>> combinationSum(vector<int> &nums , int target){
    vector<vector<int>> ans;
    vector<int> curr;
    helper(nums,ans,curr,target,0);
    return ans;
}

int main(){
    vector<int> nums = {2,3,5};
    vector<vector<int>> ans = combinationSum(nums,6);
    for(auto & element :ans){
        for (int x : element){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}