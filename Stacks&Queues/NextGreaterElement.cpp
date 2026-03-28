#include <bits/stdc++.h>
using namespace std;
//In the leet code variation for the problem just create a hashmap to asscoiate a number wiht its least greater element and then return the answer it will lead O(n) space more but giving us time of O(1)
vector<int> NextGreaterElement(vector<int> nums){
    stack<int> temp;
    vector<int> ans(nums.size());
    for(int i = nums.size()-1 ; i >=0 ; i--){
        while(!temp.empty()&&temp.top()<=nums[i]){
            temp.pop();
        }
        if(temp.empty())ans[i]=-1;
        else ans[i]=temp.top();
        temp.push(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {6,8,0,2,1,3};
    vector<int> ans = NextGreaterElement(nums);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}