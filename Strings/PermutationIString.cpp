#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> characterfrequency(string str){
    vector<int> vec(26);//incase the letters are not bounded to lowercase use unordered map for that
    for(int i = 0 ; i < str.size() ; i++){
        vec[str[i]-'a']++;//as only lower case characters are stored in our array and the denotion is a repesent 0 index ...
    }
    return vec;
}


bool doesPermutationExist(string str , string other){
    //step 1 : calculating the frequency of characters occuring in the string
    //done in the above function character frquency
    characterfrequency(str);
    //step 2 : by sliding windows based approach check whther the part of string you are checking 
    //is present or not
    for(int i = 0,j = other.size()-1 ; j<str.size(); j++,i++){
        if(characterfrequency(str.substr(i,j))==characterfrequency(other)){
            return true;
        }
    }
    return false;
}

int main(){
    string str = "dbicoooobc";
    cout<<doesPermutationExist(str, "ib")<<endl;
}