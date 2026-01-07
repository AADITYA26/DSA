#include <iostream>
#include <vector>
using namespace std;

int SieveOfEratosthenes(int n){
    vector<bool> vec(n+1,true);
    int count = 0;
    for(int i = 2 ; i<n ; i++){
        if(vec[i]==true){
            count ++;
            for(int j = i*2 ;j < n ; j = j+i){
                vec[j] =false;
            }
        }
    }
    return count;
    
}

int main(){
    cout<<SieveOfEratosthenes(50)<<endl;
}