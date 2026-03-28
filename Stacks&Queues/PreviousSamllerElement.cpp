#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int> nums){
    stack<int> temp;
    vector<int> ans(nums.size());
    for(int i =0 ; i < nums.size() ; i++){
        while(!temp.empty()&&temp.top()>=nums[i]){
            temp.pop();
        }
        if(temp.empty())ans[i] = (-1);
        else ans[i] = temp.top();
        temp.push(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {3,1,0,8,6};
    vector<int> ans = previousSmallerElement(nums);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}