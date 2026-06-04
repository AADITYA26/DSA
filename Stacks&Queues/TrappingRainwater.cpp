#include <bits/stdc++.h>
using namespace std;

vector<int> rightMax(vector<int> heights){//O(n) time , O(n) space 
    int maximum = 0;
    vector<int> ans(heights.size());
    for(int i = heights.size()-1 ; i >=0 ; i-- ){
        ans[i] = maximum;
        maximum = max(maximum,heights[i]);
    }
    return ans;
}

vector<int> leftMax(vector<int> heights ){//O(n) time , O(n) Space 
    int maximum = 0;
    vector<int> ans(heights.size());
    for(int i = 0 ; i<heights.size(); i++){
        ans[i] = maximum;
        maximum = max(maximum ,heights[i]);
    }
    return ans;
}

int TrappingRainWater(vector<int> heights){//O(n) time , o(2n) space 
    //the amount of water stored per bar = min(leftmax,rightmax)-height[i]
    //which is equal to the amount of rainwater stored as width equal 1 
    //now to calculate left max and right max 
    int sum= 0;
    vector<int> right = rightMax(heights);
    vector<int> left = leftMax(heights);
    for(int i = 1;i < heights.size()-1 ; i++){
        sum += max(0,min(right[i],left[i])-heights[i]);
    }
    return sum;
}


int TrappingRainWaterOptimized(vector<int> heights){
    int sum = 0 , rightMax =0 , leftMax = 0;
    int left = 0 ,right = heights.size()-1;
    while(left<right){
            leftMax = max(leftMax,heights[left]);
            rightMax = max(rightMax,heights[right]);
            if(heights[left]>heights[right]){
                sum+=rightMax-heights[right];
                right--;
            }
            else {
                sum+=leftMax-heights[left];
                left++;
            }
    }
    return sum;
}//checking the index and calculating max and min hegihts based on that

int main(){
    vector<int> heights = {6,3,4,5};
    cout<<TrappingRainWaterOptimized(heights)<<endl;
}