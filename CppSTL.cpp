#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
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
    cout<<"Val at index 2"<<" " <<vec.at(2)<<endl;
    //or directly access the element like an array vec[2]

    cout<<vec.front()<<" "<<"Returns the first element"<<" "<<endl;
    cout<<vec.back()<<" "<<"Returns the last element"<<endl;

    vector<int> nums(3,10);
    vector<int> nums2(nums);
    // the above functions work with O(1) time complexity so they are cheap functions
    vec.erase(vec.begin());
    //or you can use vec.erase(vec.begin()+2)
    //vec.erase(vec.begin(),vec.end())
    for(int i =0 ; i < vec.size() ; i++){
    cout<<vec[i]<<" ";}
    vec.insert(vec.begin()+2 , 100);
    //vec.clear() clears all elements  // capactiy remains same in this though
    //vec.empty checks if empty

    //Iterators : vec.begin() -> points to the first element *(vec.begin()) prints the first element
    //vec.end() : same as the last for the ending element

    vector <int> :: iterator it;//creates an iterator pointing to vector 
    for(it = vec.begin() ; it!= vec.end() ; it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
    vector<int> :: reverse_iterator rit ; //creates a reverse iterator
    for( rit = vec.rbegin() ; rit != vec.rend() ; rit++ ){
        cout<<*(rit)<<" ";//does the same thing but starts at the back reverse begin and ends at rend 
    }

    // for(vector<int> :: reverse_iterator it_ = vec.rbegin() ;it_ != vec.rend() ; it_++ ){
    //     cout<<*(it_)<<" ";//does the same thing but starts at the back reverse begin and ends at rend 
    // } //instead of writing so much use auto

    for(auto it_ = vec.rbegin() ;it_ != vec.rend() ; it_++ ){
        cout<<*(it_)<<" ";//does the same thing but starts at the back reverse begin and ends at rend 
    }
    return 0;
}

int List()
{
    list<int> l = {1,2,3};//can initiliase similar to vectors 
    l.push_back(1);
    l.push_front(10);
    l.emplace_back(2);
    l.emplace_front(3);
    l.pop_back();
    l.pop_front();
    //random access in not possible
    return 0;//all fucntions , rend , rbegin , begin , end , clear ,empty , size , insert , front , back work the same way 
}

int Deque(){
    //genral functions are same as that kf linked list
    //random access not possible
    deque<int> l = {1,2,3,4};
    for(int i=0;i<l.size();i++){
        cout<<l.at(i)<<" ";//or use l[i]
    }
    return 0;
}

int Pair(){
    pair<int,int> p ={1,2}; //you dont need to import anything to use this
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    vector<pair<int,int>> vec = {(1,2),(3,4),(5,6)};
    vec.emplace_back(7,8);
    // vec.push_back({7,8});// need to create the pair to pass it
    return 0;
}

int Stack(){//LIFO , upper part is called top , only top can be remove or added
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);//or you can use emplace
    cout<<s.top()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    s.size();
    stack<int> s2;
    s2.swap(s);//swaps the values of 2 stacks

    return 0;

}

int Queue(){
    //the same as stack but it is fifo first on forst out
    return 0;//
}

int Priorityqueue(){//stack but the highest priority element gets stored on the top
    priority_queue<int> q;//by default the priority is the largest element
    priority_queue<int , vector<int> , greater<int>> g;//greater <int> is a fucntor a comparator that helps us build a reverse order priority queue
    //priority queue time complexity O(logn) , beacuse it does sorting
}

int Map(){//key values , keys are uniques 
    map<string,int> m;
    //m[key] = value ;//insert and chnage both operations
    m["tv"]=50;
    m["tv"]=100;
    m["laptop"] = 50;
    m["headphones"] =50;//will be printed lexicographically with respect to the keys 
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}


int main(){
   Deque();
}

