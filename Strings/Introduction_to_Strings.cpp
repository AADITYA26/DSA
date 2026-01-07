#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void reverse_chararr(char str[] , int n){//n is the size of the string
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(str[start ++], str[end--]);
    }
}

int main1(){
    cout<<"Please enter your string:"<<endl;
    char str[100] ="BITS Pilani";
    //cin.getline(str,100);//the way to get the input inside the string 
    //as similar to scanf it will not take characters post the space if we enter them
    //cin.getline(str,100,',');//you can also enter a delimeter to stop the input at that point
    //also it overwrites the string 
    //cout<<str<<endl;
    char a[] = "Aaditya";//the lenght of these cannot be chnanged dynamically at runtime 
    string str2;//the lenght of these can be dynamically changed at runtime
    str2 =  str2 +str;//string cincatenation is easier in this case
    string str3 = "Dhannawat";
    cout<<(str2==str3)<<endl; //you can directly compare 
    string str4 ;
    //similar ot the earlier cin , here too you have to use getline
    getline(cin,str4,' ');//here " " is the delimeter;
    cout<<str2<<endl;
}

int main2(){
    char b[] = "Aaditya";
    reverse_chararr(b,7);
    cout<<b<<endl;
}

int main(){
    string str = "Aaditya";
    reverse(str.begin(),str.end());
    // str.at(1);
    // str[1];
    cout<<str<<endl;
}

