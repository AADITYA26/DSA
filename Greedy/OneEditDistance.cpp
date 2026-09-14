#include <bits/stdc++.h>
using namespace std;

bool OneEditDistance(string s , string t){
    int n= s.size();
    int m= t.size();
    int operations = 0;
    int i = 0 ;
    int j = 0;
    if(abs(n-m)>1)return false;
    while(i < s.size() && j < t.size()){
        if(s[i]==t[j]){
            i++ ; j++ ;
        }
        else{
            if(n==m){
                i++;
                j++;
                operations++;
            }
            if(n>m){
                i++;
                operations++;
            }
            if(m>n){
                j++;
                operations++;
            }
        }
        if(operations>1)return false;
    }
    if(n>m){
        if(operations==0 || s[i]==t[j-1])
        return true;
    }
    if(m>n){
        if(operations==0 || s[j]==t[i-1])
        return true;
    }
    return operations==1;
}

int main() {
    string s ="abc" ;
    string t ="abc" ;
    cout<<OneEditDistance(s,t);
    return 0;
}