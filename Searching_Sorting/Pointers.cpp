#include <iostream>
#include <vector>
using namespace std;

int main(){
    // int a =10;
    // int* ptr = &a;
    // int** parPtr = &ptr;
    // int* null = NULL;
    // cout<<ptr<<endl;
    // cout<<&ptr<<endl;
    // cout<<parPtr<<endl;
    // cout<<*parPtr<<endl;
    // cout<<**parPtr<<endl;

    int arr[] = {1,2,3,4,5};
    int a =15;
    //arr =&a; cannot assign it 
    //pointer arithmetic .... read on your own

}


int passByValue(int a){
    int b =10;
    a=b;
    return 0;
}

int passByReference(int* ptr){
    *ptr++;//the value of variable will change as it is 
    //getting chnaged at the memory location
}

int usingAlias(int &b){
    b=11;//using the same variable not using another number
}

