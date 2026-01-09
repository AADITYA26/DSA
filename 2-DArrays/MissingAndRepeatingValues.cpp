#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int FindRepeating(vector<vector<int>> nums){
    unordered_map<int ,pair<int , int>> map;
    for(int i = 0 ; i <nums.size() ; i++){
        for(int j = 0 ; j < nums[0].size() ; j++){
            if(map.find(nums[i][j])!=map.end()) return nums[i][j];
            else map[nums[i][j]] = {i,j};
        }        
    }
    return -1;
}

int FindMissing(vector<vector<int>> nums){
    unordered_set<int> set;
    for(int i = 0 ; i <nums.size() ; i++){
        for(int j =0 ; j<nums[0].size() ; j++){
            set.emplace(nums[i][j]);
        }
    }
    for(int i = 1; i<nums.size()*nums.size() ; i++){
        if(set.find(i)==set.end()){
            return i;
        }
    }
}

int main(){
    vector<vector<int>> vec = {{1,2,3},{3,5,6},{7,8,9}};
    int Repeating  = FindRepeating(vec);
    int Missing = FindMissing(vec);
    cout<<"Repeating :"<<Repeating<<endl;
    cout<<"Missing :"<<Missing<<endl;
}