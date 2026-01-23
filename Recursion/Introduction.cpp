#include <iostream>
#include <vector>
using namespace std;
void printNums(int n ){//O(n)
    cout<<n<<endl;
    if(n==1){
        return;
    }
    else{
        return printNums(n-1);
    }
}

int factorial(int n){//O(n)
    if(n==0) return 1;
    else return n*factorial(n-1);
}

int Nsum(int n){//O(n)
    if(n == 0) return 0;
    else return n+Nsum(n-1);
}

int fibonacci( int n ){//O(2^n)
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);
}

bool isSorted(vector<int> nums , int n){
    if(n==1||n==0) return true;
    if(nums[n-1]>=nums[n-2]) return isSorted(nums,n-1);
    else return false;
}

int binarySearch(vector<int> nums , int target , int st ,int end){
    if(st>end) return -1;
    int mid = st + (end-st)/2;
    if(nums[mid]>target) return binarySearch(nums,target,st,mid-1);
    else if (nums[mid]<target) return binarySearch(nums,target,mid+1,end);
    else return mid;
}

int search(vector<int> nums , int target){
    return binarySearch(nums,target,0,nums.size()-1);

}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    cout<<search(nums,6)<<endl;

}