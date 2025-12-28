#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution{
    public :
        static int majorityElement_bruteforce(vector<int>& nums){//O(n^2)
            for(int i =0;i<nums.size();i++){
                int count =0;
                int num = nums.at(i);
                for(int j =0 ; j<nums.size();j++){
                    if(nums.at(j)==num){
                        count++;
                    }
                }
                if(count>=nums.size()/2)
                    return num;
            }
            return INT_MIN;
        }
        static int majorityElement_optimize(vector<int>& nums){//O(nlog(n))//sorting and then just checking
            sort(nums.begin(),nums.end());
            int count =1;
            for(int i =0 ; i<nums.size()-1;i++){
                if(nums.at(i)==nums.at(i+1)){
                    count ++;
                }
                 else{
                    count =1;
                }
                if(count>nums.size()/2){
                    return nums.at(i);
                }

            }
            return INT_MIN;
        }
        static int majorityElement_moorsevooting(vector<int>& nums){//O(n)add to the vote if same nmber emove if not , if becomes 0 then frq of the most element till now = n/2 at most and we want more tha that so reset the count
            int freq = 0;
            int ans;
            for(int i = 0 ; i <nums.size() ; i++){
                if(freq==0){
                    ans = nums.at(i);
                }
                nums.at(i)==ans?freq++:freq--;
            }
            freq=0;
            for(int val:nums ){//extra step to check if the element is really the majority element cause in case it doesnt exist the voting algorithm still gives an output
                if(val == ans)
                    freq++;
            }
            if(freq>nums.size()/2)
                return ans;
            else
                return INT_MIN;

        }

};

int main(){
    vector<int> vec = {1,2,3,4};
    solution a;
    cout<<a.majorityElement_bruteforce(vec)<<endl;
    cout<<a.majorityElement_optimize(vec)<<endl;
    cout<<a.majorityElement_moorsevooting(vec)<<endl;
    return 0;
}