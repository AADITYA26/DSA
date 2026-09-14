#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &str , vector<string> &ans , string curr , int i){
    int n = str.size();
    if(i==n){
        ans.push_back(curr);
        return;
    }
    for(char c : str[i]){
        curr.push_back(c);
        dfs(str , ans , curr , i+1);
        curr.pop_back();
    }
}


vector<vector<char>> parser(string s){
    vector<vector<char>> ans;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]=='{'){
            int n = ans.size();
            i++;
            ans.push_back(vector<char>());
            while(s[i]!='}'){
                if(s[i]==','){
                    i++;
                    continue;
                }
                ans.back().push_back(s[i]);
                i++;
            }
        }
        else{
            ans.push_back(vector<char>());
            int n = ans.size();
            ans[n-1].push_back(s[i]);
        }
    }
    return ans;
}


vector<string> BraceExpansion(string s){
    vector<vector<char>> parsed_str = parser(s);
    vector<string> ans;
    string curr = "";
    dfs(parsed_str , ans , curr , 0);
    return ans;
}

int main() {
    string s = "{a,b}c{d,e}";
    vector<string> ans = BraceExpansion(s);
    for(string t : ans){
        cout<<t<<endl;
    }
    return 0;
}