#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3} ;
    //vector<int> vec ;
    //vector<int> vec(5,0); //represents size and 0 represents value
    //for each value is applicable for vectors
    cout<<vec.size()<<endl;
    for(int i: vec){
        cout<<i<<endl;
    }

    //fucntions for vectors :
    /* size --> vec.size()
       push_back() --> adding elements behind all the present ones the new one is at index vec.size()
       pop_back() --> deletes the element 
       front()
       back() gives the first and last element in the vector
       at(index)
       */
      cout<<vec.capacity()<<endl;
      vec.push_back(4);
      cout<<vec.capacity()<<endl;//capacity doubles when the limit is reached
    return 0;

}