#include <bits/stdc++.h>
using namespace std;

int longest(string & s1){
    int n = s1.size();
    int left =0, right =0;
    unordered_map<int,int> map;
    int maxlength = 0;
    int length = 0;
    while(right<n){
        if(map.find(s1[right])!=map.end()&&map[s1[right]]>=left){
            left = map[s1[right]]+1;
            map[s1[right]] = right;
        }
        else{
            map[s1[right]]=right;
        }
        length = right-left+1;
        right++;
        maxlength = max(maxlength,length);
    }
    return maxlength;
}

int main() {
    string s1 = "abcdefa";
    cout<<longest(s1);
    return 0;
}