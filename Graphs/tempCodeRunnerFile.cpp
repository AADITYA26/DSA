int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    cout<<"Adjacency List"<< " ";
    g.printAdjList();
    cout<<endl;
    vector<bool> vis(5,0);
    if(g.cycledetection(0,-1,vis)) cout<<"Cycle Detected"<<endl;
    return 0;

}