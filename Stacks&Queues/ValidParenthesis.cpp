#include <bits/stdc++.h>
using namespace std;

bool isValid(string Parenthesis){
    //when you see an opening store it 
    //when you see a closing match it with the opening 
    stack<char> stk;
    if(Parenthesis.length()%2!=0)return false;
    for(int i = 0 ; i <Parenthesis.length() ; i++){
        if(Parenthesis[i] == '('||Parenthesis[i] == '['||Parenthesis[i] == '{') stk.push(Parenthesis[i]);
        else{
            if(stk.empty())return false;
            char c = stk.top();
            if((c=='('&&Parenthesis[i]==')')||(c=='{'&&Parenthesis[i]=='}')||(c=='['&&Parenthesis[i]==']')){
                stk.pop();
            }
            else return false;
        }
    }
    return stk.empty();//checking if the stack is empty if not then extra elements with no ending bracket
    //only valid path reaches the end
}

int main(){
    vector<string> abc = {"()","({[]})","([)]",")(","(((",""};
    for(string i : abc)
    cout<<isValid(i)<<endl;
}