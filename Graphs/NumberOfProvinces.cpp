#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion{
    public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSetUnion(int n){
        this -> n = n;
        par.resize(n);
        rank.resize(n);

        for(int i = 0 ; i < n ; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }

    void Union(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA]==rank[parB]){
            par[b] = parA;
            rank[parA]++;//ranks only increase if the ranks are same 
        }

        else if(rank[parA]>rank[parB]){
            par[parB] = parA;//if the ranks are not same then ranks wont increase
        }//beacuse the root added wont increase the size

        else{
            par[parA] = parB;
        }
    }

    int find(int a){
        if(par[a] == a ){
            return a;
        }
        return par[a] = find(par[a]);//path compression directly assigns the final parent to the nodes
    }

};

int numberOfprovinces(vector<vector<int>> matrix){
    int n = matrix.size();
    DisjointSetUnion temp(n);
    int count  = n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){//we can do j = i+1 to reduce the complexity to n^2/2
            if(matrix[i][j]==1){
                if(temp.find(i)!=temp.find(j)){
                    temp.Union(i,j);
                    count--;
                }
            }
        }
    }
    return count;
}