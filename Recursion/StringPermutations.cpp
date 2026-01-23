#include <iostream>
#include <vector>
using namespace std;

void getPerms(string str , int index , vector<string>& ans){//O(n!*n) time complexity
    if(index ==str.length() ){
        ans.push_back(str);
        return;
    }
    for(int i  = index ; i<str.length() ; i++){
        swap(str[i],str[index]);
        getPerms(str,index+1,ans);
        swap(str[i],str[index]);
    }
}

vector<string> Permutations (string str){
    vector<string> ans;
    getPerms(str, 0 , ans);
    return ans;
}

int main(){
    vector<string> ans = Permutations("BIT");
    for(string element : ans){
    cout<<element<<endl;
}
return 0;
}