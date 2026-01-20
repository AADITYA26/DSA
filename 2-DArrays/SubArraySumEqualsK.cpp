#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int SubArraySum_BruteForce(vector<int> nums , int target){
    int n = nums.size();//O(n^2) time complexity
    int count =0 ;
    for(int i = 0; i<n ; i++){
        int sum =0;
        for(int j =i ; j<n; j++){
            sum += nums[j];
            if(sum == target) count++;
        }
    } 
    return count;   
}

int SubArraySum_Optimal(vector<int> nums , int target){//Based on the approach of prefix sum
    int n = nums.size();//SubArraySum(i,j) = PS[j]-PS[i-1]
    int count =0;
    vector<int> prefix_sum(n);
    unordered_map<int,int> map;
    int sum =0 ;
    for(int i = 0 ; i < n ; i++){
        sum += nums[i];
        prefix_sum[i] = sum;
    }
    for(int i = 0 ; i < n ; i ++){
        // int other  = prefix_sum[i] - target;
        if (prefix_sum[i] == target)count ++;//if prefix sum directly equals target then 
        else if(map.find(prefix_sum[i]-target)!=map.end())count += map[prefix_sum[i]-target];//if there exists a prefix sum with the given target  the increase freq 
        else if(map.find(prefix_sum[i])==map.end())map[prefix_sum[i]]=0;//if it doesnt exist then initialize it with 0
        map[prefix_sum[i]]++;
    }
    return count;
}

int main(){
    vector<int> nums = {0,0,0};
    int count = SubArraySum_Optimal(nums,0);
    cout<<count<<endl;
}