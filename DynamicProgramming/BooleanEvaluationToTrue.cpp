#include <bits/stdc++.h>
using namespace std;

int booleanEvalTrue(string & s1 , int i , int j , bool isTrue){
    if(i>j)return 0;
    if(i==j){
        if(isTrue)return s1[i]=='T';
        else return s1[i]=='F';
    }
    int total = 0;
    for(int k = i+1 ; k < j ; k+=2){
        int AND = 0;
        int OR = 0;
        int XOR = 0;
        int LT = booleanEvalTrue(s1,i,k-1,1);
        int RT = booleanEvalTrue(s1,k+1,j,1);
        int LF = booleanEvalTrue(s1,i,k-1,0);
        int RF = booleanEvalTrue(s1,k+1,j,0);
        if(isTrue){
            if(s1[k]=='&')AND = LT*RT;
            if(s1[k]=='|')OR = LT*RT+LF*RT+LT*RF;
            if(s1[k]=='^')XOR = LT*RF+LF*RT;
        }
        else{
            if(s1[k]=='|')OR = LF*RF;
            if(s1[k]=='&')AND = LF*RT+LF*RF+LT*RF;
            if(s1[k]=='^')XOR = LT*RT+LF*RF;
        }
        total += AND + OR + XOR;
    }
    return total;
}

int tab(string s1){
    int n = s1.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i = 0 ; i < n ; i ++){
        dp[i][i][1] = (s1[i]=='T');
        dp[i][i][0] = (s1[i]=='F'); 
    }
    for(int i = n-1 ; i >= 0 ; i-=2){
        for(int j = i+2 ; j < n ; j+=2){
            for(int x = 0 ; x<=1 ; x++){
                int total = 0;
                for(int k = i+1 ; k < j ; k+=2){
                    int AND = 0;
                    int OR = 0;
                    int XOR = 0;
                    int LT = dp[i][k-1][1];
                    int RT =  dp[k+1][j][1];
                    int LF = dp[i][k-1][0];
                    int RF = dp[k+1][j][0];
                    if(x){
                        if(s1[k]=='&')AND = LT*RT;
                        if(s1[k]=='|')OR = LT*RT+LF*RT+LT*RF;
                        if(s1[k]=='^')XOR = LT*RF+LF*RT;
                    }
                    else{
                        if(s1[k]=='|')OR = LF*RF;
                        if(s1[k]=='&')AND = LF*RT+LF*RF+LT*RF;
                        if(s1[k]=='^')XOR = LT*RT+LF*RF;
                    }
                    total += AND + OR + XOR;
                }
                dp[i][j][x] = total;
            }
        }
    }
    return dp[0][n-1][1];
}

int main() {
    string s = "T";
    cout<<tab(s);
    return 0;
}