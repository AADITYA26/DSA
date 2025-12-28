#include <iostream>
#include <vector>
using namespace std;

class solution{
    public :
    static vector<int> PairSum(vector<int>& nums , int targetSum){
      vector<int> num;
        for(int i= 0; i < nums.size() ; i++){
            for(int j =0 ; j<nums.size() ; j++){
                if(nums.at(i)+nums.at(j) == targetSum){
                    num.push_back(nums.at(i));
                    num.push_back(nums.at(j));\
                    return num;
                }
            }
        }
        return num;
    }
    static vector<int> PairSum2(vector<int>& nums , int targetSum){
        int sum;//2 pointer approach if > , array is sorted similary for <
        vector<int> vec ;
        int start = 0;
        int end = nums.size() -1;
        //sum = nums.at(start)+nums.at(end);
        while(sum != targetSum ){
            sum = nums.at(start)+nums.at(end);
            if(sum==targetSum){
                vec.push_back(nums.at(start));
                vec.push_back(nums.at(end));
                return vec;
            }
            if(sum<targetSum){
                start++;
            }
            if(sum>targetSum){
                end--;
            }
        }
        return vec;
    }
};

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8};
    solution a;
    vector<int> ans = a.PairSum2(vec,15);
    cout<<ans.size()<<endl;
    for(int an :ans){
        cout<<an<<endl;
    }
    return 0;
}