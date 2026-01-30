#include <iostream>
#include <vector>
using namespace std ;
bool isSafe(vector<vector<char>>& board , int row , int column , int n ){
    for(int i  = 0 ; i < n ; i ++){//checking for queens in the same row
        if(board[row][i] == 'Q') return false;}
    for(int i = 0 ; i <n ; i++){//checking for queens in the same column
        if(board[i][column] == 'Q') return false;}
    for(int i = row ,j = column ; i >=0 && j>=0 ; i--,j--) 
        if(board[i][j]=='Q') return false;
    for(int i = row ,j = column ; i >=0 && j<n ; i--,j++) 
        if(board[i][j]=='Q') return false;
    return true;
}

void NQueens(vector<vector<char>>& board , int row , int n , vector<vector<vector<char>>>& ans){//placing n queens in n rows instead of n*n directly
    if(row == n ){
    ans.push_back(board);
    return;
    }
    for(int i = 0 ; i < n ; i++){
        if(isSafe(board , row , i , n )){
            board[row][i] = 'Q';
            NQueens(board , row+1 , n,ans);
            board[row][i] = '.';
        }
    }
    return;    
}

int main(){
    int n = 5;
    vector<vector<char>> board(n,vector<char>(n,'.')) ;
    vector<vector<vector<char>>> ans;
    NQueens(board , 0 , n , ans);
    int N= 0 ;
    for(vector<vector<char>> board : ans){
        for(vector<char> row : board){
            for(char element : row){
                cout<<element;
            }
            cout<<endl;
        }
        N++;
        cout<< "Iteration : " << N <<endl<<endl;
    }
}