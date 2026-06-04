#include <bits/stdc++.h>
using namespace std;

int FirstUniqueCharacter(string str){
    unordered_map<char,int> freq;
    queue<int> temp;
    for(int i = 0 ; i <str.size() ; i++){
        if(freq.find(str[i])==freq.end()){
            freq[str[i]] = 1;
            temp.push(i);
        }
        else {
            freq[str[i]]++;
        }
    }
    while(!temp.empty()){
        if(freq[str[temp.front()]]!=1)temp.pop();
        else return temp.front();
    }
    return -1;
}

int main(){
    string str = "level";
    cout<<FirstUniqueCharacter(str)<<endl;
}