#include <iostream>
#include <string>
using namespace std;

string CompressionOfString(string str){
    string ans = "";
    for(int i = 0 ; i<str.size() ;i++){
        ans += str[i];
        int count = 1;
        while(str[i]==str[i+1]&&i<str.size()){
            count++;
            i++;
        }
        ans+=to_string(count);
    }
    return ans;
}

int main(){
    string a = "aaabbbcccddd";
    cout<<CompressionOfString(a)<<endl;
}