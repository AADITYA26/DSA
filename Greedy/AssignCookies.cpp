#include <bits/stdc++.h>
using namespace std;

int assigncookies(vector<int> greed , vector<int> cookies){
    sort(cookies.begin(),cookies.end());
    sort(greed.begin(),greed.end());
    int count = 0;
    int cookie_ptr = 0;
    int greed_ptr = 0;
    while(cookie_ptr<cookies.size()&&greed_ptr<greed.size()){
        if(greed[greed_ptr]<=cookies[cookie_ptr]){
            count++;
            greed_ptr++;
            cookie_ptr++;
        }
        else{
            cookie_ptr++;
        }
    }
    return count;
}

int main() {
    vector<int> greed = {1,2,3};
    vector<int> cookies = {1,1};
    cout<<assigncookies(greed,cookies);
    return 0;
}