#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &price , int length , int index){
    if(length == 0)return 0;
    if(index == 0){
        if(length>=1)return price[0]*length;
        else return -1e9;
    }
    int notpick = rodCutting(price , length , index -1);
    int pick = -1e9;
    if(length >= index+1){
        pick = price[index] + rodCutting(price , length-index-1 , index );
    }
    return max(pick,notpick);
}

int main() {
    
    return 0;
}