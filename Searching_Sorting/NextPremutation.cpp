#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPemutation(vector<int>& nums){
    int n =nums.size();
    int pivot = -1;
    for(int i = n-1 ; i >0 ; i--){
        if(nums[i-1]<nums[i]){
            pivot = i-1;
            break;
        }
    }
    if(pivot==-1){
        reverse(nums.begin(),nums.end());
    }
    for (int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    //reverse(nums.begin()+pivot+1, nums.end());
    int i = pivot+1,j=n-1;
    while(i<=j){//revesering the array after
        swap(nums[i++],nums[j--]);
    }

}

int main(){
    vector<int> vec = {1,3,6,5,2};
    nextPemutation(vec);
    for(int i = 0 ;i <vec.size() ; i++){
        cout<<vec[i];
        cout<<" ";
    }
}