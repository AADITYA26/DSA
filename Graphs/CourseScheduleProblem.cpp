#include <bits/stdc++.h>
using namespace std;
enum COLOR{
    WHITE,//unvisited node
    GREY,//currently visiting node
    BLACK//visited all its neighbours
};

bool courseScheduleProblemhandler(vector<vector<int>> &prereq , int numCourses  , vector<COLOR>& color , int src , stack<int>& topo){
    if(color[src]==BLACK)return true;
    if(color[src]==GREY) return false;
    color[src]=GREY;
    for(auto x : prereq){
        if(x[1]==src){
            if(!courseScheduleProblemhandler(prereq,numCourses,color,x[0],topo))return false;
        }
    }
    color[src]=BLACK;
    topo.push(src);
    return true;
}

bool courseSchedule(vector<vector<int>> &prereq , int numCourses){//for a better time complexity you can convert prereq into an adj matrix 
    //this will reduce the time comeplexity from the current O(VE) to O(V+E)
    vector<COLOR> color(numCourses,WHITE);
    stack<int> topo;
    for(int i = 0 ; i < numCourses ; i++){
        if(color[i]==WHITE){
            if(!courseScheduleProblemhandler(prereq,numCourses,color,i,topo)){
                return false;
            }
        }
    }
    int size = topo.size();
    for(int i = 0 ; i < size ; i++){
        int x = topo.top();
        cout<<x<<endl;
        topo.pop();
    }
    return true;
}

int main(){
    vector<vector<int>> vec = {{1,0},{2,0},{3,1},{3,2}};
    if(courseSchedule(vec,4))cout<<"Correct"<<endl;
    else cout<<"Incorrect"<<endl;
}