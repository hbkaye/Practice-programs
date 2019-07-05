/*
    *This code finds out vertex with maximum number of path
    *from a given starting point.
 */



#include <bits/stdc++.h>
 
using namespace std;
 
void topo(int start, vector<int> mat[], unordered_map<int, int>& um){
    if(mat[start].empty()){                                 //Checking for element with no descendants
        um[start]++;
        return;
    }
    for(auto i : mat[start]) topo(i, mat, um);
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int island, edges, start;
    unordered_map<int, int> um;                             //Using hash table
    cin >> island >> edges >> start;                        //Input vertex, edges, starting point
    vector<int> mat[island+1];                              //Using a vector
    for(int i =0; i< edges; i++){
        int fir, sec;
        cin >> fir >> sec;
        mat[fir].push_back(sec);
    }                                                       //Inserted elements in vector
    topo(start, mat, um);                                   //Function to find out element and--
    int max = -1;                                           //--storing in table
    vector<int> ret;
    for(auto i : um){                                       //Searching table for maximum value
        if(i.second > max){
            max = i.second;
            ret.clear();
            ret.push_back(i.first);
        }                                                   
        else if(i.second == max){
            ret.push_back(i.first);
        }
    }
    sort(ret.begin(), ret.end());                           //Sorting all valid values
    for(auto i : ret){                                      //Printing values
        cout << i << " ";
    }
	return 0;
}