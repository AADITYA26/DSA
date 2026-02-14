#include <iostream>
#include <vector>
using namespace std;

bool KnightsTour(vector<vector<int>> matrix , int r , int c , int expVal){
    int n =matrix.size();
    if(r<0||c<0||r>=n||c>=n||matrix[r][c]!=expVal) return false;//if the val is not equal to expVal then return false
    if(expVal == n*n-1) return true;//return true if the knight reaches the end    
    bool ans1 = KnightsTour(matrix , r+2 ,c-1 , expVal+1);//8 possible move combinations that the knight can take 
    bool ans2 = KnightsTour(matrix , r+1 ,c-2 , expVal+1);//check if each is true
    bool ans3 = KnightsTour(matrix , r+2 ,c+1 , expVal+1);
    bool ans4 = KnightsTour(matrix , r+1 ,c+2 , expVal+1);
    bool ans5 = KnightsTour(matrix , r-2 ,c-1 , expVal+1);
    bool ans6 = KnightsTour(matrix , r-2 ,c+1 , expVal+1);
    bool ans7 = KnightsTour(matrix , r-1 ,c-2 , expVal+1);
    bool ans8 = KnightsTour(matrix , r-1 ,c+2 , expVal+1);
    return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
}

int main(){
    vector<vector<int>> grid = {
    { 0, 21, 10, 15,  6},
    {11, 16,  7, 20,  9},
    {24,  1, 22,  5, 14},
    {17, 12,  3,  8, 19},
    { 2, 23, 18, 13,  4}
};
    cout<<"Returned :"<<KnightsTour(grid , 0 ,0 , 0)<<endl;
}