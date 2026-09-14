#include <bits/stdc++.h>
using namespace std;
int maxpath_up(vector<vector<int>> grid , int r ,int c , vector<vector<int>> dp){
    if(r<0||c<0||c>=grid.size())return 0;
    if(dp[r][c]!=-1)return dp[r][c];
    int maxcount = 0;
    for(int i = -1 ; i <=1 ; i++){
        maxcount = max(maxcount , grid[r][c]+maxpath_up(grid ,r-1 , c+i,dp));
    }
    return dp[r][c] = maxcount;}


int main() {
    
    return 0;
}