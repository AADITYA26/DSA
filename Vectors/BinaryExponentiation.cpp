#include <iostream>
#include <bitset>
using namespace std ;

class solution{
    public:
    static int POW(double x , int n){//the code here uses binary exponentaition keeping in mind the binary for n
        int ans =1;//inititailaizing the final answer as 1
        if(x==0)return 0;
        if(x==1)return 1;
        if(x==-1&&n%2==0)return 1;
        if(x==-1&&n!=1)return -1;
        if(n==0)return 1;
        if(n<0){
            x = 1/x;
            n = -n;
        }
        while(n>0){
            if(n&1)ans *=x;
            x*=x;
            n>>=1;//dividing by 2 to get the get the next integer for the operation
        }
        return ans;
    }
};