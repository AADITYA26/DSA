#include <bits/stdc++.h>
#include "Introduction.cpp"
using namespace std;

void dfs(vector<vector<char>> & grid , vector<vector<bool>> & vis , int r , int c){
    if(r<0||r>=grid.size()||c<0||c>=grid[0].size())return;
    else if(grid[r][c]=='0'||vis[r][c]==true)return;
    vis[r][c] = true;
    dfs(grid,vis,r+1,c);
    dfs(grid,vis,r,c+1);
    dfs(grid,vis,r,c-1);
    dfs(grid,vis,r-1,c);
}

int numIslands(vector<vector<char>> &grid){
    if(grid.size()==0)return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> vis(rows,vector<bool>(cols,0));
    int count = 0;
    for(int i = 0 ; i < rows ; i++){
        for(int j =0 ; j<cols ; j++){
            if(!vis[i][j]&&grid[i][j]=='1'){
                count++;
                dfs(grid,vis,i,j);
            }
        }
    }
    return count;
}