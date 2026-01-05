#include <iostream>
#include <vector>
using namespace std;

int Vector(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.emplace_back(4);//Same but creates the new object before storing    
    vec.pop_back();
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    cout<<"Val at index 2"<<vec.at(2)<<endl;
    //or directly access the element like an array vec[2]

    cout<<vec.front()<<"Returns the first element";
    cout<<vec.back()<<"Returns the last element";

    vector<int> nums(3,10);
    return 0;
}