#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int>arr , int NoOfBoards , int MaxAllowedTime , int NoOfPainters){
    int sum =0;
    int numsPainters =1;
    for(int i = 0 ; i < NoOfBoards ; i++){
        if(arr[i]> MaxAllowedTime) return false;
        if(sum + arr[i] > MaxAllowedTime){
            numsPainters ++;
            sum =arr[i];
        }
        else{
            sum += arr[i];
        }
    }
    if(numsPainters > NoOfPainters) return false;
    else return true;
}
int minTimeToPaint(vector<int>& arr ,int NoOfBoards , int NoOfPainters){
    if(NoOfBoards <NoOfPainters) return -1;
    int sum = 0;
    for(int ar :arr){
        sum +=ar;
    }
    int st =0 , end =sum;
    int ans =-1;
    while(st <=end){
        int mid = st +(end-st)/2;
        if(isValid(arr , NoOfBoards ,mid , NoOfPainters )){
            ans =mid;
            end =mid-1;
        }
        else st  =mid+1;
    }
    return ans;
}
int main(){
    vector<int> pages = {22,23,67};
    cout<<minTimeToPaint(pages,3,2)<<endl;
}