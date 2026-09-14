#include <bits/stdc++.h>
using namespace std;

int helper(vector<string>& board , int i , int j , vector<vector<bool>>& vis){
    int n = board.size();
    if(i == (n-1)&& j == (n-1))return 0;
    int UP  = 1e9;
    int DOWN = 1e9;
    int LEFT = 1e9;
    int RIGHT = 1e9;
    if((i-1)>=0 &&board[i-1][j] == 'D' && vis[i-1][j]){
        vis[i-1][j] = 0;
        UP = helper(board , i-1 , j , vis);
    }
    if((j-1)>=0 &&board[i][j-1] == 'D' && vis[i][j-1]){
        vis[i][j-1] = 0;
        LEFT = helper(board , i , j-1 , vis);
    }
    if((i+1)<n &&board[i+1][j] == 'D' && vis[i+1][j]){
        vis[i+1][j] = 0;
        DOWN = helper(board , i+1 , j , vis);
    }
    if((j+1)<n &&board[i][j+1] == 'D' && vis[i][j+1]){
        vis[i][j+1] = 0;
        RIGHT = helper(board , i , j+1 , vis);
    }
    return 1 + min({UP , DOWN  , LEFT , RIGHT});
}