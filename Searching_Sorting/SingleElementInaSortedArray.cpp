#include <iostream>
#include <vector>
using namespace std;

int SingleElement(vector<int>& nums){
    int n =nums.size();
    int st =0 ;
    int end =nums.size()-1;
    if(n==1)return 0;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if(mid==0&&nums[0]!=nums[1])return 0;
        if(mid==(n-1)&&nums[n-1]!=nums[n-2])return n-1;
        // If mid is the single element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Check if we are on the "normal" side (before the single element)
        // Normal pattern: (Even index matches Next) OR (Odd index matches Previous)
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
            (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
            st = mid + 1; // Move Right
        } 
        else {
            end = mid - 1; // Move Left
        }
    }
    return -1;
}

int main(){
    vector<int> vec ={2,2,3,3,4,5,5};
    cout<<SingleElement(vec)<<endl;
}