#include <bits/stdc++.h>
using namespace std;



int LongestBitonicSeq(vector<int> nums){
    int n = nums.size();
    vector<int> dp_f(n,1);
    vector<int> dp_b(n,1);
    int maxi = 1;
    for(int i = 0 ; i < n ; i++){
        for(int prev = 0 ; prev <i ; prev++  ){
            if(nums[i]>nums[prev]){
            dp_f[i] = max(dp_f[i],dp_f[prev]+1);}
            if(nums[n-i-1]>nums[n-prev-1]){
            dp_b[n-i-1] = max(dp_b[n-i-1],dp_b[n-prev-1]+1);}
        }
    }
    for(int i = 0; i < n ; i++){
        maxi = max(dp_f[i]+dp_b[i]-1,maxi);
    }
    return maxi;
}

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }
    int query(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};
int LongestBitonicSequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> vals = nums;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> rank(n);
    for (int i = 0; i < n; i++)
        rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;
    int m = vals.size();
    vector<int> lis(n), lds(n);
    // LIS ending at i
    Fenwick fw1(m);
    for (int i = 0; i < n; i++) {
        lis[i] = fw1.query(rank[i] - 1) + 1;
        fw1.update(rank[i], lis[i]);
    }
    // LDS starting at i
    Fenwick fw2(m);
    for (int i = n - 1; i >= 0; i--) {
        lds[i] = fw2.query(rank[i] - 1) + 1;
        fw2.update(rank[i], lds[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1);
    return ans;
}
int main() {
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << LongestBitonicSequence(nums);
}
