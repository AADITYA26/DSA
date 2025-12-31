#include <iostream>
#include <vector>
using namespace std;

void mergeAndSort(vector<int>& n , vector <int>& m){
    int n_size = n.size();
    int m_size = m.size();
    int i =m_size-1,j=n_size-m_size-1 ,index = n_size-1;//no.of elemrnts after the sorted part
    while(i>=0 && j>=0){
        if(m[i]>=n[j]){
            n[index]=m[i];
            i--;
            index--;
        }else{
            n[index] = n[j];
            j--;
            index--;
        }
    }
    while(i>=0){
        n[index] = m[i];
        i--;
        index--;
    }
}

int main(){
    vector<int> n = {2,3,0,0,0,0,0};
    vector<int> m = {1,2,5,6,8};
    mergeAndSort(n,m);
    for(int i = 0 ;i <n.size() ; i++){
        cout<<n[i];
        cout<<" ";
    }
}