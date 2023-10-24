#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//implementation using adjacency list
template <typename T>
class graph{
    public:
    unordered_map<T, list<T> > adj;
    void addEdges(T u, T v, bool direction){
        // direction = 0 -> undirected
        // direction = 1 -> directed
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printEdges(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    graph<int> g;
    int n = 5; // n is no of nodes
    int m = 6; // m is the no of edges
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addEdges(u, v, 0);
    }
    g.printEdges();
    return 0;
}