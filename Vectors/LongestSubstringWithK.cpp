#include <bits/stdc++.h>
using namespace std;

int LongestSubstringwithAtmostK(string s , int k){
    int n = s.size();
    int left = 0 ; 
    int right = 0;
    int length = 0;
    int maxLength = 0;
    unordered_map<int,int> map;
    while(right < n){
        map[s[right]]++;
            while(map.size()>k){
                char l = s[left];
                left++;
                map[l]--;
                if(map[l]==0)map.erase(l);
            }
        length = right-left+1;
        maxLength = max(length , maxLength);
        right++;
    }
    return maxLength;
}


int main() {
    string s = "aabbccc";
    cout<<LongestSubstringwithAtmostK(s,2);
    return 0;
}