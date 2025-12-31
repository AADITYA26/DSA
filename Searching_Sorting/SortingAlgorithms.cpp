#include <iostream>
using namespace std;
void BubbleSort(int arr[] , int n){//Optimized Bubble sort ... O(n^2)
    for(int i = 0 ; i<n ; i++){
        bool isSwap =false;//for checking if the further element is already sorted
        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
                isSwap =true;
            }
        }
        if(!isSwap)return;//array is already sorted 
    }
}

void SelectionSort(int arr[] , int n){
    for(int i =0 ;i <n ; i++){
        int SmallestIndex = i;
        for(int j =i ; j<n ; j++){
            if(arr[SmallestIndex]>arr[j]){
                SmallestIndex = j;
            }
        }
        swap(arr[SmallestIndex] ,arr[i]);
    }
}

void InsertionSort(int arr[],int n){//O(n^2)
    for(int i =1; i<n ;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >=0 &&arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]= curr;
    }
}


int main(){
    int arr[] = {5,4,3,2,1};
    //BubbleSort(arr,5);
    //SelectionSort(arr,5);
    InsertionSort(arr,5);
    for(int i = 0 ;i <5 ; i++){
        cout<<arr[i];
        cout<<" ";
    }
}