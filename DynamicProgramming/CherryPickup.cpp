#include <bits/stdc++.h>
using namespace std;

int MaxCherry(vector<vector<int>> cherry , int i, int j1  , int j2){
    if(j1<0||j2<0||j1>cherry[0].size()-1||j2>cherry[0].size()-1)return -1e9;
    if(i==cherry.size()-1) {
        if(j1==j2) return cherry[i][j1];
        if(j1!=j2) return cherry[i][j1]+cherry[i][j2];
    }
    int MAX  = -1e9;
    for(int k = -1 ; k < 2 ; k++){
        for(int j = -1 ; j < 2 ; j++){
            if(j1==j2){
                MAX = max(MAX,cherry[i][j1]+MaxCherry(cherry,i+1 , j1+k , j2+j));
                continue;
            }
            MAX = max(MAX , cherry[i][j1]+cherry[i][j2]+MaxCherry(cherry,i+1 , j1+k , j2+j ));
        }
    }
    return MAX;
    }

    int MaxCherryMeomization(vector<vector<int>> cherry , int i, int j1  , int j2 ,vector<vector<vector<int>>>& dp ){
        if(j1<0||j2<0||j1>cherry[0].size()-1||j2>cherry[0].size()-1)return -1e9;
        if(i==cherry.size()-1) {
            if(j1==j2) return dp[i][j1][j2]=cherry[i][j1];
            if(j1!=j2) return dp[i][j1][j2]=cherry[i][j1]+cherry[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int MAX  = -1e9;
        for(int k = -1 ; k < 2 ; k++){
            for(int j = -1 ; j < 2 ; j++){
                if(j1==j2){
                    MAX = max(MAX,cherry[i][j1]+MaxCherryMeomization(cherry,i+1 , j1+k , j2+j,dp));
                    continue;
                }
                MAX = max(MAX , cherry[i][j1]+cherry[i][j2]+MaxCherryMeomization(cherry,i+1 , j1+k , j2+j,dp ));
            }
        }
        return dp[i][j1][j2] = MAX;
        }

int tabulation(vector<vector<int>> cherry){
    vector<vector<vector<int>>> dp(cherry.size(),vector<vector<int>>(cherry[0].size(),vector<int>(cherry[0].size(),0)));
    int n = cherry.size();
    int m = cherry[0].size();
    //3-D Dp into 2-D Dp for space optimisation 
    for(int j1 = 0 ; j1 < m ; j1++){
        for(int j2 = 0; j2<m ; j2++){
            if(j1==j2)dp[n-1][j1][j2] = cherry[n-1][j1];
            else{dp[n-1][j1][j2] = cherry[n-1][j1] + cherry[n-1][j2];}
        }
    }
    for(int i = n-2 ; i >= 0 ; i++){
        for(int j1 = 0 ; j1 < m ; j1++){
            for(int j2 = 0 ; j2 < m ; j2++){
                int MAX  = -1e9;
            for(int k = -1 ; k < 2 ; k++){
                for(int j = -1 ; j < 2 ; j++){
                    if(j1+k>=0&&j1+k<m&&j2+j>=0&&j2+j<m){
                    if(j1==j2){
                        MAX = max(MAX,cherry[i][j1]+dp[i+1][j1+k][j2+j]);
                        continue;
                    }
                    MAX = max(MAX , cherry[i][j1]+cherry[i][j2]+dp[i+1][j1+k][j2+j]);}
                }
            }
            dp[i][j1][j2] = MAX;
            }
        }
    }
    return dp[0][0][m-1];
}

int main() {
    
    return 0;
}