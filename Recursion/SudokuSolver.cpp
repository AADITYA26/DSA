#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool isOkay(vector<vector<string>>&Sudoku , int &row ,int &col , int n){
    for(int i = 0 ; i < 9  ; i ++){
        if(Sudoku[row][i] == to_string(n)) return false;
    }
    for(int i = 0 ; i <9 ; i ++){
        if(Sudoku[i][col] == to_string(n)) return false;
    }
    for(int i = 0 ; i < 3 ; i++ ){
        for(int j = 0; j < 3 ; j++){
            if(Sudoku[row/3*3 +i][col/3*3+ j] == to_string(n)) return false;
        }
    }
    return true;
}

void helper(vector<vector<string>>& Sudoku , int row , int col , bool& solved){
    if(row == 9) {
        solved = true;
        return ;}
    if(col >=9 ) return helper(Sudoku,row+1,0,solved);
    if(Sudoku[row][col] != ".") return helper(Sudoku , row , col+1 , solved);
    for(int j =1 ; j < 10 ; j++){
        if(isOkay(Sudoku , row , col ,j)){
            Sudoku[row][col] = to_string(j);   
            helper(Sudoku , row , col +1 , solved);
            if(solved) return;
            Sudoku[row][col] = '.';             
        }
    }
    return;
}

void SudokuSolver(vector<vector<string>>&Sudoku){
    bool solved = false;
    helper(Sudoku , 0 ,0 , solved);
}

int main(){
    vector<vector<string>> board =  {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}} ; 
    float starttime  = clock();
    SudokuSolver(board);
    float endtime  = clock();
    cout<<(endtime-starttime)/CLOCKS_PER_SEC<<endl;
    for(auto& row : board){
        for(auto element : row){
            cout<<element<<" ";
        }
        cout<<endl;
    }
}

//Errors done by me :
//Backtracking was done even after the sudoku was solved 
//some minor mistakes like did not multiply row/3*3 and col/3*3