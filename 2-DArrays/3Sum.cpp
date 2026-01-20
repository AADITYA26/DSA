#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

set<vector<int>> SumTripletsBruteforce(vector<int> nums ,int target){//O(n^3)
    set<vector<int>> ans ;
    for(int i=0; i <nums.size();i++){
        int first = nums[i];
        for(int j =i+1 ; j<nums.size() ; j++){
            int second = nums[j];
            for(int k =j+1 ; k<nums.size() ; k++){
                int third = nums[k];
                vector<int> a = {first,second,third};
                sort(a.begin(),a.end());
                if((first+second+third) == target) ans.insert({first,second,third});
            }
        }
    }
    return ans;
}

set<vector<int>> SumTripletsOptimized_Hashing(vector<int> nums , int target){//my approach
    unordered_map<int , unordered_map<int , int>> map;//O(n^2log(n))There is a simplified approach for this by just 2 loopss
    //for a and b and then dirctly finding c , so no need for layered map make it without it 
    set<vector<int>> ans;
    for(int i =0 ; i<nums.size();i++){
        int part_target = target - nums[i];
        for(int j = i+1 ; j<nums.size() ; j++){
            int second  = part_target - nums[j];
            if(map[nums[i]].find(second)!=map[nums[i]].end()){
                vector<int> a = {nums[i],nums[j],second};
                sort(a.begin(),a.end());
                ans.insert(a);
            }
            else map[nums[i]][nums[j]] = j;
        }
    }
    return ans;
}

vector<vector<int>> SumTriplets_2Pointer(vector<int> nums , int target){//this approach removes the need for using the set
    //making the time complexity O(n^2) only
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i = 0 ; i<nums.size()-2 ; i++){
        if(i>0&&nums[i]==nums[i-1])continue;//avoids running the loop multiple times 
        int j = i+1 , k=nums.size()-1;//which also makes sure duplicates dont come
        while(j<k){
            if(target == nums[i]+nums[j]+nums[k]){
                ans.push_back({nums[i],nums[j],nums[k]}) ;
                j++;
                k--;
            }
            else if(target > nums[i]+nums[j]+nums[k]) j++;
            else{k--;
            while(j<k && nums[j]==nums[j-1])j++;//similary for j here
            }            
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1};
    vector<vector<int>> ans = SumTriplets_2Pointer(nums,0);
    for(int i=0 ;i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}