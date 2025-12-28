#include <iostream>
#include <vector>
using namespace std;


class solution{
    public:
    static int MostWater(vector<int>& height){
        int MostWater =0;
        int InitialBar = 0;
        int EndingBar = height.size()-1;
        while(InitialBar<EndingBar){
            MostWater = max(MostWater,min(height.at(InitialBar),height.at(EndingBar))*(EndingBar-InitialBar));
            if(height.at(EndingBar)<height.at(InitialBar))EndingBar--;
            else InitialBar++;
            }
        return MostWater;
    }
    static int MostWater_BruteForce(vector<int>& height){
        int MostWater = 0;
        for(int i = 0 ; i<height.size();i++){
            for(int j = i; j<height.size() ; j++){
                if(MostWater<min(height.at(i),height.at(j))*(j-i)){
                    MostWater = min(height.at(i),height.at(j))*(j-i);
                }
            }
        }
        return MostWater;
    }
};

int main(){
    solution a ;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout<<a.MostWater(heights)<<endl;
}