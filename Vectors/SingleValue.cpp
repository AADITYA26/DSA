#include <iostream>
#include <vector>
using namespace std;

class solutions{
    public:
        static int singleNumber(vector<int>& nums){//&allows to directly deal on the original vector and doesnt crate a copy basically it changes to pass by reference
            for(int i =0 ; i<nums.size();i++){
                int count =0;
                for(int j =0 ; j<nums.size();j++){
                    if(nums.at(i)==nums.at(j)){
                        count++;
                    }
                }
                if(count == 1){
                    return nums.at(i);
                }
            }
            cout<<"NO SUCH NUMBER"<<endl;
            return 0;
        }
    int singleNumber2(vector<int>& nums){//XOR of anynumber with itself is 0 leaving only the nonduplicate number behind
        int number=0;
        for(int i =0 ; i <nums.size() ; i++){
            number = number ^ nums.at(i);
        }
        return number;
    }
};

int main(){
    vector<int> vec = {2,2,3,1,1,3,4};
    solutions sol;
    cout<<sol.singleNumber2(vec)<<endl;
    return 0;
    }
