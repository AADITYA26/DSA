#include <iostream>
using namespace std;

int gcd (int a , int b){
    if(a==0||b==0) return a+b;
    if(a>b) gcd(a%b,b);
    else if(b>a) gcd(a,b%a);
}
int lcm(int a , int b ){
    return a*b/gcd(a,b);
}
int main(){
    cout<<gcd(28,20)<<endl;
}