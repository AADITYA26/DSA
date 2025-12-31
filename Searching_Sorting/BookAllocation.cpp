#include <iostream>
#include <vector>
using namespace std;

bool isValid(int pages[] , int m , int maxAllowedPages, int n){
    int students = 1;
    int sum = 0;
    for(int i =0 ; i<n ;i++){
        if(pages[i]>maxAllowedPages)return false;
        if(sum+pages[i]>maxAllowedPages){
            students++;
            sum =pages[i] ;
        }
        else{
            sum+=pages[i];
        }

    }
    if(students>m)return false;
    else  return true;
}

int findPages(int arr[], int n, int k) {
    // code here
    if(n<k) return -1;
    int st =0 ;
    int end =0;
    for(int i =0 ; i<n ;i++){
        end+=arr[i];
    }

    int mid =0 ;
    int ans =-1;
    while(st<=end){
        mid = st + (end-st)/2;
        if(isValid(arr ,k, mid , n)){
            ans = mid;
            end = mid-1;
        } 
        else st =mid+1;
    }
    return ans;
}
int main(){
    int pages[] = {22,23,67};
    cout<<findPages(pages,3,1)<<endl;
}