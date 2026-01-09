#include <iostream>
#include <vector>
using namespace std;

//O(n) space complexity approach simply use sets to do so

//Constant space complexity -- Slow Fast Pointer Approach

int FindDuplicate(vector<int> nums){//beacuse the array onyl contains elements form 1-n we can take the value of the node as the pointer to another 
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(slow!=fast);
    slow = nums[0];
    do{
        slow = nums[slow];
        fast = nums[fast];
    }
    while(slow !=fast);
    return slow;

}

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,2};
    int duplicate  = FindDuplicate(vec);
    cout<<duplicate<<endl;
}
//this approach does this in O(n) time complexity and O(1) space complexity