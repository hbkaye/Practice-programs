#include <iostream>
#include <list>
#include <vector>

using namespace std;

class graph{
    int ver;
    list<int> *ptr;

    void DFSUtil(int ver, vector<bool> &visited);
    public: 
        graph(int ver); 
        void addEdge(int v, int w); 
        void print(int start); 
};
graph::graph(int ver){
    this->ver = ver;
    ptr = new list<int>[ver];
}
void graph::addEdge(int v, int w) 
{ 
    ptr[v].push_back(w); // Add w to v’s list. 
} 
void graph::DFSUtil(int v, vector<bool>& visited){
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator itr;
    for(itr = ptr[v].begin(); itr != ptr[v].end(); itr++){
        if(visited[(*itr)] == false){
            DFSUtil(*itr, visited);
        }
    }
}
void graph::print(int start){
    vector <bool> visited(ver, false); 
    DFSUtil(start, visited);
}

int main() 
{ 
    // Create a graph given in the above diagram 
    graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
    g.print(6);
    return 0; 
} 