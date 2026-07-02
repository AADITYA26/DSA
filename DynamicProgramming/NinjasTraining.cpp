#include <bits/stdc++.h>
using namespace std;

int NinjasTraining(vector<vector<int>> &Schedule , int day , int last){
    if(day<0)return 0;
    int total = 0;
    for(int i = 0 ; i < 3 ; i++){
        if(last!=i){
            total = max(total, Schedule[day][i]+NinjasTraining(Schedule,day-1,i));
        }
    }
    return total;
}

int NinjasTraining_memoization(vector<vector<int>> &Schedule , int day , int last  , vector<vector<int>> &dp){
    if(day==0){
        int Max = 0;
        for(int i = 0 ; i < 3 ;i++){
            if(last!=i)Max = max(Max,Schedule[0][i]);
        }
        return Max;
    }
    int total = 0;
    if(dp[day][last]!=-1)return dp[day][last];
    for(int i = 0 ; i < 3 ; i++){
        if(last!=i){
            total = max(total, Schedule[day][i]+NinjasTraining_memoization(Schedule,day-1,i,dp));
        }
    }
    return dp[day][last] = total;
}
//in dp number of loops = number of state variables then there 1 internal loop in this case for choosing
int NinjasTraining_tabulation(vector<vector<int>> &Schedule){
    vector<vector<int>> dp(Schedule.size(),vector<int>(4,-1));
    int n = Schedule.size();
    dp[0][0] = max(Schedule[0][1],Schedule[0][2]);
    dp[0][1] = max(Schedule[0][0],Schedule[0][3]);
    dp[0][2] = max(Schedule[0][0],Schedule[0][1]);
    dp[0][3] = max(Schedule[0][0],Schedule[0][1],Schedule[0][2]);
    for(int i = 1 ;i <n ; i++){
        for(int last = 0 ; last < 4 ; last++){
            int total = 0;
            for(int j = 0 ; j < 3 ;j ++){//this part is exactly the same as recursion
                if(j!=last)
                total = max(total,dp[i-1][j]+Schedule[i][j]);
            }
            dp[i][last] = total;
        }
    }
    return dp[n-1][3];    
}

int NinjasTraining_optimal(vector<vector<int>> & Schedule){
    int n = Schedule.size();
    vector<int> prev(4,0);
    int ans = 0;
    prev[0] = max(Schedule[0][1],Schedule[0][2]);
    prev[1] = max(Schedule[0][2],Schedule[0][0]);
    prev[2] = max(Schedule[0][1],Schedule[0][0]);
    prev[3] = max({Schedule[0][0],Schedule[0][1],Schedule[0][2]});
    for(int i = 1; i < n ;i ++){
        vector<int> curr(4,0);
        for(int last  =0 ; last < 4 ; last++){
            int total = 0;
            for(int task = 0 ; task < 3; task++){
                if(last!=task){
                    total = max(total , prev[task]+Schedule[i][task]);
                }
            }
            curr[last] = total;
        }
        for(int i =0 ; i < 4 ;i++)prev[i] = curr[i];
    }
    return prev[3];
}

int main() {
    
    return 0;
}