#include <bits/stdc++.h>
using namespace std;


vector<int> NextGreaterElement(vector<int> nums){
    stack<int> temp;
    vector<int> ans(nums.size());
    int n = nums.size();
    for(int i = 2*n-1 ; i >=0 ; i--){
        int tempi = i%n;
        while(!temp.empty()&&temp.top()<=nums[tempi]){
            temp.pop();
        }
        if(temp.empty()) ans[tempi] = -1;
        else ans[tempi] = temp.top();
        temp.push(nums[tempi]);
    }
    return ans;
}

int main(){
    vector<int> nums = {3,6,5,4,2};
    vector<int> ans = NextGreaterElement(nums);
    for(int i =0 ; i < nums.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}