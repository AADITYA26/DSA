#include <bits/stdc++.h>
using namespace std;

int CelebrityProblem(vector<vector<int>> nums){//O(n^2) O(1) space
    for(int i =0 ;i <nums.size(); i++ ){
        int sum_column = 0;
        int celebrity = 0;
        for(int j = 0 ;j <nums[0].size();j++){
            if(nums[j][i]==0) celebrity = j;
            sum_column += nums[j][i];
        }
        if(sum_column==nums.size()-1){
            bool isCelebrity = 1;
            for(int i =0 ;i <nums.size()-1 ;i++){
                if(nums[i][sum_column]!=0){
                    isCelebrity = false;
                    break;
                }
            }
            if(isCelebrity)return celebrity;
            else continue;
        }
    }
    return -1;
}


int CelebrityProblemOptimized(vector<vector<int>> nums){//O(n) time and O(n) space
    stack<int> temp;//checking the pairs of numbers by using stack
    for(int i =0 ; i < nums.size() ; i++) temp.push(i);
    while(temp.size()>1){
        int a = temp.top();temp.pop();
        int b = temp.top();temp.pop();
        if(nums[a][b]) temp.push(b);
        else temp.push(a);
    }
    int c = temp.top();
    for(int i = 0 ; i<nums.size();i++)  if(nums[c][i])return -1;
    for(int i = 0 ; i<nums.size();i++){
        if(i==temp.top())continue;
        if(!nums[i][c])return -1;
    }
    return c;
}

int main(){
    vector<vector<int>> nums = {{0,1,0},{0,0,0},{0,1,0}};
    cout<<CelebrityProblemOptimized(nums);
}