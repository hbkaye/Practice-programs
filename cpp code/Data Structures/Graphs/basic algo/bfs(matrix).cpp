#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void BFS(vector<vector<int>> vec, int start){
    int i = start;
    queue<int> q;
    vector<int> visited (vec[i].size() , 0);

    cout << i << " ";
    visited[i] = 1;
    q.push(i);

    while(!q.empty()){
        i = q.front();
        q.pop();
        for(int j = 1; j <= vec[i].size(); j++){
            if(vec[i][j] == 1 && visited[j] == 0){
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return;

}

int main(){
    vector<vector<int>> G
                {{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
    BFS(G, 5);

    return 0;
}