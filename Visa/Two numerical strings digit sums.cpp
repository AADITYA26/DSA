#include <bits/stdc++.h>
using namespace std;

string addition(string s1 , string s2 ){
    int i = s1.size()-1 ;
    int j = s2.size()-1 ;
    string ans;
    while(i >=0 && j >=0){
        int a = s1[i]- '0';
        int b = s2[j]- '0';
        ans+= to_string(a+b);
        i--;j--;
    }
    while(i >=0){
        ans+=s1[i];
        i--;
    }
    while(j>=0){
        ans+=s2[j];
        j--;
    }
    reverse(ans.begin() , ans.end());
    return ans ;
}


int main() {
    
    return 0;
}