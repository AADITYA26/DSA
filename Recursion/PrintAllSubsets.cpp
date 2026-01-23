#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void PrintSusbsets(vector<int> nums  , vector<int> ans , int i){
    if(i==nums.size()){
        for (int i = 0 ; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    ans.push_back(nums[i]);
    PrintSusbsets(nums,ans,i+1);
    ans.pop_back();//backtracking step
    PrintSusbsets(nums,ans,i+1);
}


void allSubsets(vector<int> nums  , vector<int> ans , int i , vector<vector<int>>& final){
    if(i==nums.size()){
            final.push_back(ans);        
            return ;
    }
    ans.push_back(nums[i]);
    allSubsets(nums,ans,i+1,final);
    ans.pop_back();//backtracking step
    allSubsets(nums,ans,i+1,final);
}

void duplicateSubsets(vector<int> nums , vector<int> ans , int i ,  set<vector<int>>& final){//mymethod increase time cpmplexity due to sorting
    if(i==nums.size()){//insertion in a set takes log(n) time complexity
        final.insert(ans);        
        return ;
    }
    ans.push_back(nums[i]);
    duplicateSubsets(nums,ans,i+1,final);
    ans.pop_back();//backtracking step
    duplicateSubsets(nums,ans,i+1,final);
}

void duplicateSets_optimal(vector<int> nums,vector<int> ans , int i , vector<vector<int>> & final){
    sort(nums.begin(),nums.end());
    if(i==nums.size()){
        final.push_back(ans);        
        return ;
    }

    ans.push_back(nums[i]);
    duplicateSets_optimal(nums,ans,i+1,final);
    ans.pop_back();//backtracking step
    int index = i+1;
    while(index<nums.size()&&nums[index]==nums[index-1]){//skipping the elements which are the same 
        //to make sure duplicate arrays are not repeated
        index++;
    }
    duplicateSets_optimal(nums,ans,index,final);
}


int main(){
    vector<vector<int>> ans = {} ;
    duplicateSets_optimal({1,2,2},{},0,ans);
    for(vector<int> element : ans){
        for(int j = 0 ; j<element.size() ; j++){
            cout<<element[j]<<" ";
        }
        cout<<endl;
    }
}