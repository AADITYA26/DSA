#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<char>>& grid , queue<pair<int,int>>& q , int rows , int cols , bool &spread){
    int sz = q.size();
    for(int i = 0  ; i < sz ; i++){
        auto temp = q.front();
        int r = temp.first;
        int c = temp.second;
        q.pop();
        if(r-1>=0 && grid[r-1][c]=='1') {
            q.push({r-1,c});
            grid[r-1][c] = '2';
            spread = true;
        }
        if(c-1>=0 && grid[r][c-1]=='1') {
            q.push({r,c-1});
            grid[r][c-1] = '2';
            spread = true;
        }
        if(r+1<rows && grid[r+1][c]=='1') {
            q.push({r+1,c});
            grid[r+1][c] = '2';
            spread = true;
        }
        if(c+1<cols && grid[r][c+1]=='1') {
            q.push({r,c+1});
            grid[r][c+1] = '2';
            spread = true;
        }
    }
}

int RottingOranges(vector<vector<char>>& grid){
    queue<pair<int,int>> q;
    int rows = grid.size();
    int cols = grid[0].size();
    if(grid.size() == 0)return -1;
    for(int i = 0 ; i < grid.size() ; i ++){
        for(int j = 0 ; j <grid[0].size() ; j++){
            if(grid[i][j]=='2'){
                q.push({i,j});
            }
        }
    }
    int time = 0 ;
    while(!q.empty()){
        bool spread = 0;
        bfs(grid ,q,rows,cols , spread);
        if(spread) time++;
    }
    for(int i =0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            if(grid[i][j]=='1'){
                return -1;
            }
        }
    }
    return time;
}