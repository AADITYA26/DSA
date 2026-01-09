#include <iostream>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> nums){//My method
    vector<int> ans;
    int rows = nums.size();
    int cols = nums[0].size();
    int r= 0 ;
    int c =0 ;
    int count = 0;
    while(count < rows*cols){// my method tracks over the inner rectangles one by one here r,c represent inner and outer rectangle coordinates 
        for(int i = c ; i <= cols-c-1&&count < rows*cols ; i++,count++) ans.push_back(nums[r][i]);//top
        for(int i = r+1 ; i <= rows-r-1&&count < rows*cols;i++,count++) ans.push_back(nums[i][cols-c-1]);//right
        for(int i = cols-c-2 ; i >= c&&count < rows*cols ; i--,count++) ans.push_back(nums[rows-r-1][i]);//bottom
        for(int i = rows-r-2 ; i >=r+1&&count < rows*cols ; i-- , count++)ans.push_back(nums[i][c]);// count check in every for loop to prevent overflowing //left
        r++ ,c++;}
    return ans;
}

vector<int> SpiralMatrix2(vector<vector<int>> nums){
    vector<int> ans;
    int rows = nums.size();
    int cols = nums[0].size();
    int srow = 0 , erow = rows-1;
    int scol =0 , ecol = cols -1;
    while(srow<=erow && scol <= ecol){
        for(int i = scol ; i <=ecol ; i++) ans.push_back(nums[srow][i]);//top
        for(int i = srow +1 ; i <=erow ; i++) ans.push_back(nums[i][ecol]);//right
        for(int i = ecol -1 ; i >=scol ; i--){
            if(srow == erow) break;
            ans.push_back(nums[erow][i]);//bottom
        }
        for(int i = erow-1 ; i >srow ; i--){
            if(scol == ecol) break;
            ans.push_back(nums[i][scol]);//left
        }
        srow ++ ,scol ++ ; 
        erow -- , ecol --;
    }
    return ans;
}

int main(){
    vector<vector<int>> nums = {{1,2,3 ,4,5},{4,5,6,7,8},{7,8,9,10,11}};
        vector<int> ans = SpiralMatrix2(nums);
    for(int i =0 ; i <ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}