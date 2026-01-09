#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int,int> PairSum(vector<int> nums , int target){
    unordered_map<int , int> map;
    for(int i = 0 ; i<nums.size() ; i++){
        int first = nums[i];
        int second  = target -first;
        if(map.find(second)!=map.end()){
            return {i , map[second]};
        }
        map[first] = i;//creating another element if not present        
    }

}

int main(){
    vector<int> no = {1,2,3,4,5,6,7,8,9};
    pair<int,int> p = PairSum(no,10);
    cout<<p.first<<" "<<p.second<<" "<<endl;
}