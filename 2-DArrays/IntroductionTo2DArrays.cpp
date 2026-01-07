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


bool BinarySearcg(vector<vector<int>> nums){
    int rows = nums.size();
    int cols = nums[0].size();
    int row_st = 0 ,row_ed = rows-1 , col_st = 0 ,col_ed = cols-1;

    while(row_st<=row_ed){
        int row_md = row_st + 
    }
}