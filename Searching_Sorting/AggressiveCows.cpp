#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& arr, int NoOfPositions , int NoOfCows , int Distance){
    int start =0 ;int numCows=1;
    for(int i = 0 ; i< NoOfPositions ; i++){//O(N)
        if(arr[i]-arr[start] >= Distance){
            numCows++;//if distance between pos becomes grater then distance 
            start = i;
        }
    }
    if(numCows >= NoOfCows)return true;//if no. of cows that are possible is more than the given number
    return false;
}

int getDistance(vector<int>& arr, int NoOfPositions , int NoOfCows){//overall Time complexity O(nlog(N))
    if(NoOfPositions < NoOfCows) return -1;
    sort(arr.begin(),arr.end());//O(Nlog(N))
    int start =0 , end = arr[NoOfPositions-1]-arr[0];
    int ans =0;
    while(start <= end ){//Olog(n) .... overall it becomes O(Nlog(Range))
        int mid = start +(end-start)/2;
        if(isValid(arr , NoOfPositions , NoOfCows ,mid)){
            ans = mid;//left
            start = mid+1;
        }
        else end =mid-1;  //right         
    }
    return ans;
}

int main(){
    vector<int> pos = {1,2,8,4,9};
    cout<<getDistance(pos,5,3)<<endl;
}