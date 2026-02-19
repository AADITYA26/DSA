#include <iostream>
using namespace std;
//Isnt anything special , preferred if you dont read it.
//Your wish though dont blame me later;
void one(int n);
void two(int n);

void one(int n){
    n++;
    cout<<"The first function"<<" "<<n<<endl;
    two(n);
    return;
}


void two(int n){
    n++;
    cout<<"the second function"<<" "<<n<<endl;
    one(n);
    return;
}

int main(){
    one(0);
}
