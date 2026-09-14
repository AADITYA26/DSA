#include <iostream>
#include <vector>
using namespace std;

class solution{
    public :
        static int max(int a , int b){
            return a>b?a:b;
        }
        static int KadaneAlgorithm(vector<int>& nums){//dont add a negative number to the current sums
            int currentSum = 0;
            int maxSum = INT_MIN;
            for(int i = 0 ; i< nums.size() ; i++){
                currentSum += nums.at(i);
                maxSum = max(currentSum,maxSum);
                if(currentSum<0){
                    currentSum =0 ;
                }
            }
            return maxSum;
        }
};

int main(){
    vector<int> vec ={1,2,-1,3,4,5,-3};
    solution sol;
    cout<<sol.KadaneAlgorithm(vec)<<endl;
}