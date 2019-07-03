#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int ver1, int ver2){
    adj[ver1].push_back(ver2);
    adj[ver2].push_back(ver1);
}

void printGraph(vector<int> adj[], int SIZE){
    for(int i =0; i< SIZE; i++){
        cout << "\n Adjacency list of vertex "
             << i << "\n head "; 
        for (auto x : adj[i]) 
           cout << "-> " << x; 
        printf("\n"); 
    }
}

int main() 
{ 
    int SIZE = 5; 
    vector<int> adj[SIZE]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, SIZE); 
    return 0; 
} 