#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> SumTripletsBruteforce(vector<int> nums ,int target){
    vector<vector<int>> ans ;
    for(int i=0; i <nums.size();i++){
        int first = nums[i];
        for(int j =i ; j<nums.size() ; j++){
            int second = nums[j];
            for(int k =j ; k<nums.size() ; k++){
                int third = nums[k];
                if((first+second+third) == target) ans.push_back({first,second,third});
            }
        }
    }
    return ans;
}

vector<vector<int>> SumTripletsOptimized_Hashing(vector<int> nums , int target){
    unordered_map<int , unordered_map<int , int>> map;
    for(int i =0 ; i<nums.size(),i++){
        int part_target = target - nums[i]
    }
}