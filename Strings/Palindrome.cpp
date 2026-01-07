#include <iostream>
#include <string>
using namespace std;

bool isAlphanumeric(char a){
    if((a>='0'&&a<='9')||(tolower(a)>='a'&&tolower(a)<='z')) return true;
    else return false;
}

bool isPalindrome(string str){
    int start =0;
    int end = str.size()-1;
    while(start <end){
        if(!isAlphanumeric(str[start])){ start ++;continue;}
        if(!isAlphanumeric(str[end])){end--;continue;}
        if(tolower(str[start])!=tolower(str[end])){
            return false;
        }
        else{
            start++;
            end--; }      
    }
    return true;
}

int main(){
    cout<<isPalindrome("racecar")<<endl;
}