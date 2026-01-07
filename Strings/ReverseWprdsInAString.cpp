#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ReverseWordsIntheString(string str){
    reverse(str.begin(),str.end());
    string ans;
    string word;
    for(int i =0 ; i<str.size() ; i++){
        if(str[i]!= ' ') word +=str[i];
        else if(word.size()>0&& str[i] == ' ') {
            reverse(word.begin(),word.end());
            ans= ans + word +" ";
            word = "";
        }
        else word ="";
    }
    if(word.size()>0){
        reverse(word.begin(),word.end());
        ans+=word;
        word="";
    }
    return ans;
}

int main(){
    string str = "BITS Pilani";
    cout<<ReverseWordsIntheString(str)<<endl;
}