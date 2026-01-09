#include <iostream>
#include <vector>
using namespace std;

pair<int,int> LinearSearch(int matrix[][4] ,int rows,int columns , int element){
    for(int i = 0 ; i<rows ; i++ ){
        for(int j =0 ; j<columns; j++){
            if(matrix[i][j]==element){
                return {i,j};
            }
        }
    }
}

int MaxRowSum(int matrix[][4] , int rows , int columns ,int element){
    int MaxRowSum =INT32_MIN;
    for(int i = 0 ; i <rows ; i++){
        int sum =0 ;
        for(int j = 0 ; j<columns ; j++){
            sum+=matrix[i][j];
        }
        MaxRowSum = max(MaxRowSum , sum);
    }
    return MaxRowSum;
}

void Vectors2D(){
    vector<vector<int>> vec = {{1,2,3},{4,5,6 ,10,11},{7,8,9}};//dynamix sizing possible directly
    //rows = mat.size()
    //columns = mat[i].size()
}


bool BinarySearch(vector<vector<int>> nums ,int target){//Approach 1
    int rows = nums.size();
    int cols = nums[0].size();
    if(rows ==0||cols == 0) return false;
    int row_st = 0 ,row_ed = rows-1 , col_st = 0 ,col_ed = cols-1 , row =-1;
    while(row_st<=row_ed){
        int mid = (row_st + row_ed)/2;
        if(target>=nums[mid][0]&&target<=nums[mid][cols-1]) {row = mid;break;}
        else if(target>nums[mid][cols-1]) row_st = mid+1;
        else row_ed = mid-1;        
    }
    if(row==-1) return false;
    while(col_st<=col_ed){
        int mid = (col_st+col_ed)/2;
        if(target==nums[row][mid])return true;
        if(target>nums[row][mid]) col_st = mid+1;
        else col_ed = mid-1;
    }
    return false;
}

bool BinarySearch2(vector<vector<int>> nums ,int target){
    int rows = nums.size();
    int cols = nums[0].size();
    int lo = 0 , hi = rows*cols-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        int r = mid/cols;
        int c = mid%cols;
        if(nums[r][c]==target)return true;
        else if (nums[r][c]<target) lo = mid +1;
        else hi = mid-1;
    }
    return false;
}

bool BinarySearch3(vector<vector<int>> nums ,int target){
    int rows = nums.size();
    int cols = nums[0].size();
    int r = 0;
    int c = cols-1;
    while(c>=0&&r<rows){
        if(nums[r][c] == target) return true;
        if(target < nums[r][c]) c--;
        else if(target > nums[r][c]) r++;
    }
    return false;
}

int main(){
    vector<vector<int>> vec = {{1,3,5},{2,4,6},{7,8,9}};
    cout<<BinarySearch3(vec , 10)?1:0;//O(m*n)
}