#include <bits/stdc++.h>
using namespace std;

int largestRectInHist(vector<int> hist){
    int n = hist.size();
    vector<int> nextsmaller(n,0);
    vector<int> prevsmaller(n,0);
    stack<int> temp;
    for(int i = n-1 ; i >=0 ; i--){
        while(!temp.empty()&&hist[temp.top()]>=hist[i]){
            temp.pop();
        }
        if(temp.empty())nextsmaller[i] = n;
        else nextsmaller[i] = temp.top();
        temp.push(i);
    }
    stack<int> newstack;
    temp.swap(newstack);
    for(int i = 0 ; i <n ; i++){
        while(!temp.empty()&&hist[temp.top()]>=hist[i]){
            temp.pop();
        }
        if(temp.empty())prevsmaller[i] = -1;
        else prevsmaller[i] = temp.top();
        temp.push(i);
    }
    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        int width = nextsmaller[i] - prevsmaller[i] - 1;
        maxi = max(maxi , width*hist[i]);
    }
    return maxi;
    
}

int MaximumRectArea(vector<vector<int>> nums , int n , int m ){
    vector<int> height(m , 0);
    int maxArea = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(nums[i][j]==1)height[j] ++;
            else height[j] = 0;
        }
        maxArea = max(maxArea , largestRectInHist(height));
    }
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
    {1,0,1,0,0},
    {1,0,1,1,1},
    {1,1,1,1,1},
    {1,0,0,1,0}
    };
    cout<<MaximumRectArea(mat,4,5);
    return 0;
}