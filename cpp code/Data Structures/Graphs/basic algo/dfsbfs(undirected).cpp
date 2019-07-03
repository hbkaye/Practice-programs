#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define l 6

using namespace std;

void addEdge(vector<vector<int>>& vec, int ver1, int ver2){
    vec[ver1].push_back(ver2);
    vec[ver2].push_back(ver1);
    return;
}

static bool visited[l] = {false};

void DFS(vector<vector<int>> vec, int start){
    if(visited[start] == false){
        cout << start << " ";
        visited[start] = true;
        for(int i = vec[start][0]; i < vec[start].size(); i++){
            if(visited[vec[start][i]] == false){
                DFS(vec, vec[start][i]);
            }
        }
    }
}

void BFS(vector<vector<int>> vec, int start){
    int i = start;
    queue<int> q;
    vector<int> visited (vec.size() , 0);

    cout << i << " ";
    visited[i] = 1;
    q.push(i);

    while(!q.empty()){
        i = q.front();
        q.pop();
        for(int j = 0; j < vec[i].size(); j++){
            if( visited[vec[i][j]] == 0){
                cout << vec[i][j] << " ";
                visited[vec[i][j]] = 1;
                q.push(vec[i][j]);
            }
        }
    }
    return;
}

int main(){
    vector<vector<int>> adj (l);
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    addEdge(adj, 3, 5); 
    addEdge(adj, 5, 4); 
    addEdge(adj, 2, 5); 
    
    DFS(adj, 2);
    cout << endl;
    BFS(adj, 2);

    return 0;
}