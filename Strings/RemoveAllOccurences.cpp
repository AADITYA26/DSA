#include <iostream>
#include <string>
using namespace std;

void removeAllOccurences(string& a , string part){//mymethod
    while(a.find(part)!=-1){
        int index = a.find(part);
        a.erase(index,part.size());
    }

}

int main(){
    string c = "daabcabaabcbc";
    removeAllOccurences(c,"abc");
    cout<<c<<endl;
}