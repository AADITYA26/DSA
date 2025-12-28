#include <iostream>
#include <vector>
using namespace std;

class solution{
    public:
        static vector<int> ArrayProduct(vector<int>& nums){//O(n) for time . O(n) for space
            int n= nums.size();
            if(n==0)return {};
            if(n==1)return {1};
            vector<int> prefix(n);
            vector<int> suffix(n);
            vector<int> ans;
            prefix[0] = 1;
            suffix[n-1] = 1;
            for(int i = 1; i < n ; i++){
                prefix[i] = prefix[i-1]*nums.at(i-1);
            }
            for(int i = n-2 ; i >=0 ; i--){
                suffix[i] = suffix[i+1]*nums.at(i+1);
            }
            for(int i = 0 ; i <n ; i++){
                ans.push_back(prefix[i]*suffix[i]);
            }
            return ans;
        }
    static vector<int> ArrayProduct_BruteForce(vector<int>& nums){//O(n^2) for time . O(1) for space
        int product =1;
        vector<int> ans;
        for(int i =0 ; i<nums.size()-1;i++){
            for(int j=0;j<nums.size()-1;j++){
                if(j!=i){
                    product *= nums.at(j);
                }
            }
            ans.push_back(product);
            product=1;
        }
        return ans;
        }

    static vector<int> ArrayProduct_Optimized(vector<int>& nums){//O(n) for time . O(1) for space
        int n= nums.size();         
        vector<int> ans(n,1);
        for(int i = 1; i < n ; i++)
            ans[i] = ans[i-1] * nums[i-1];
        int suffix =1;
        for(int i = n-1 ; i >=0 ; i--){
            ans[i] *= suffix;  
            suffix *= nums[i];//ith suffix calculation
        }
        return ans;
    }

};

int main(){
    vector<int> vec = {1,2,3,4};
    solution a;
    vector<int> sol = a.ArrayProduct_Optimized(vec);
    cout<<"["<<" ";
    for(int s : sol){
        cout<<s<<" ";
    }
    cout<<"]"<<"";
}