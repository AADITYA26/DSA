class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penalty(customers.size()+1, 0);
        int inti = 0;
        for(int i  =0   ; i < n ; i++){
            if(customers[i]=='Y')inti++;
        }
        penalty[0] = inti;
        for(int i = 1 ; i <= n ; i++){
            if(customers[i-1]=='N'){
                penalty[i] = penalty[i-1]+1;
            }
            else{
                penalty[i] = penalty[i-1]-1;
            }
        }
        int ans = *min_element(penalty.begin() , penalty.end());
        int ans_index = find(penalty.begin() , penalty.end() , ans)-penalty.begin();
        return ans_index;
    }
};