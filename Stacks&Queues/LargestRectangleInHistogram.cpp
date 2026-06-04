#include <bits/stdc++.h>
using namespace std;


vector<int> rightSmallerElement(vector<int> &nums){//O(n) time , O(n) space 
    stack<int> temp;
    vector<int> ans(nums.size());
    for(int i= nums.size()-1 ; i >=0; i --){
        while(!temp.empty()&&nums[temp.top()]>=nums[i]){
            temp.pop();
        }
        if(temp.empty()) ans[i] = nums.size();
        else ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}

vector<int> leftSmallerElement(vector<int>& nums){//O(n) time , O(n) space
    stack<int> temp;
    vector<int> ans(nums.size());
    for(int i= 0 ; i <=nums.size()-1; i ++){
        while(!temp.empty()&&nums[temp.top()]>=nums[i]){
            temp.pop();
        }
        if(temp.empty()) ans[i] = -1;
        else ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}
int LargestAreaInHistorgram(vector<int>& nums){//O(n) time, O(2n) space
    vector<int> right = rightSmallerElement(nums);
    vector<int> left = leftSmallerElement(nums);
    int maxArea = 0;
    for(int i =0 ; i <nums.size(); i ++){
        int currArea = nums[i]*(right[i]-left[i]-1);
        maxArea = max(currArea,maxArea);
    }
    return maxArea;
}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout<<LargestAreaInHistorgram(heights)<<endl;
}