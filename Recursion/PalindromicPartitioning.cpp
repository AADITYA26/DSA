#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string str){
    int st = 0, end = str.length()-1;
    while(st<=end){
        if(str[st]!=str[end]) return false;
        st++ , end--;
    }
    return true;
}

void getAllPartitions(string str , vector<string>& partitions , vector<vector<string>> &ans){
    if(str.size()==0){
        ans.push_back(partitions);
        return;
    }
    for(int i = 0; i<str.size() ; i++){//slices after every index to check for partitioning
        if(isPalindrome(str.substr(0,i+1))){
            partitions.push_back(str.substr(0,i+1));
            getAllPartitions(str.substr(i+1),partitions , ans);
            partitions.pop_back();
        }
    }
}

int main(){
    string str = "aba";
    vector<vector<string>> ans ;
    vector<string> parts;
    getAllPartitions(str , parts , ans);
    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}