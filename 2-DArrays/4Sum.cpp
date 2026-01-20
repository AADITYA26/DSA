#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> SumTriplets_2Pointer(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < nums.size(); ) {

            int st = j + 1;
            int end = nums.size() - 1;

            while (st < end) {
                long long sum =
                    (long long)nums[i] + nums[j] + nums[st] + nums[end];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[st], nums[end]});
                    st++; end--;
                    while (st < end && nums[st] == nums[st - 1]) st++;
                }
                else if (sum > target) {
                    end--;
                }
                else {
                    st++;
                }
            }
            j++;
            while (j < nums.size() && nums[j] == nums[j - 1]) j++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    vector<vector<int>> ans = SumTriplets_2Pointer(nums,10);
    for(int i=0 ;i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
    }
}