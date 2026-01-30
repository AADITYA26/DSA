#include <iostream>
#include <vector>
#include <string>
using namespace std;

//where we have to find all the possible solutions we use recursion to solve the problem
//1:D , 2:R , 3:L , 4:U
bool isSafe(vector<vector<int>> maze , int row , int col ){
    if(row<0 || col <0 || row>maze.size()-1 || col>maze.size()-1) return false;
    if(maze[row][col] == 0) return false;
    if(maze[row][col] == 1) return true;
}

void RatMazeSolver(vector<vector<int>> &maze , vector<string>& ans , int row , int col , string &curr){
    if(row == maze.size()-1&&col == maze.size()-1) {
        ans.push_back(curr);
        row = 0;
        col =0 ;
        return;
    }
    //DOWN
    maze[row][col] = 0;//Have visited the cell before 
    if(isSafe(maze,row+1,col)){
        curr.push_back('D');
        RatMazeSolver(maze,ans,row+1,col,curr);
        // maze[row][col] = 1;
        curr.pop_back();
    }
    //RIGHT
    if(isSafe(maze,row,col+1)){
        curr.push_back('R');
        RatMazeSolver(maze,ans,row,col+1,curr);
        // maze[row][col] = 1;
        curr.pop_back();
    }
    maze[row][col] = 1;
    return;
}

int main(){
    vector<vector<int>> maze  =  {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans ;
    string curr;
    RatMazeSolver(maze ,ans,0,0,curr );
    for(auto element : ans){
        cout<<element<<endl;
    }
}