#include <bits/stdc++.h>
using namespace std;

bool NumCustomers(vector<int> customers){
    int change5 = 0;
    int change10 = 0;
    for(int i = 0 ; i < customers.size() ; i++){
        if(customers[i]==5)change5+=1;
        else if(customers[i] == 10){
            if(change5>=1){
                change5--;
                change10++;
            }
            else return false;
        }
        else {
            if(change5>=1&&change10>=1){
                change5--;
                change10--;
            }
            else if(change5>=3)change5-=3;
            else return false;
        }
    }
    return true;
}

int main() {
    vector<int> customers = {5,5,5,10,20};
    cout<<NumCustomers(customers);
    return 0;
}