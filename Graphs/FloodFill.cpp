#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image , int orgColor , int newColor , int sc , int sr){
    if(sc<0||sr<0||sr>=image.size()||sc>=image[0].size())return;
    if(image[sr][sc]==newColor||image[sr][sc]!=orgColor) return;
    image[sr][sc] = newColor;
    dfs(image , orgColor , newColor , sc ,sr+1);
    dfs(image , orgColor , newColor , sc+1 ,sr);
    dfs(image , orgColor , newColor , sc ,sr-1);
    dfs(image , orgColor , newColor , sc-1 ,sr);
}

vector<vector<int>> floddFill(vector<vector<int>> &image , int orgColor , int newColor , int sc , int sr){
    dfs(image , orgColor , newColor , sc,sr);
    return image;
}