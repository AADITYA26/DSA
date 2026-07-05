#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string & s1 , string & s2){
    int n = s1.length();
    int m = s2.length();
    vector<int> prev(m+1,0);
    for(int i = 1; i< n+1 ; i++){
        vector<int> curr(m+1,0);
        for(int j = 1 ; j < m+1 ; j++){
            if(s1[i-1]==s2[j-1]){
                curr[j] = 1 + prev[j-1];
                continue;
            }
            int option1 = prev[j];
            int option2 = curr[j-1];
            curr[j] = max(option1,option2);
        }
        prev = curr;
    }
    return prev[m];
}

int minIns_Del(string A , string B){
    int l = LongestCommonSubsequence(A,B);
    int deletions = A.length()-l;
    int insertions = B.length()-l;
    return insertions+deletions;
}


int main() {
    
    return 0;
}