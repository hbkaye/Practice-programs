#include <bits/stdc++.h>
using namespace std;

vector<int> recombine(vector<int> &first, vector<int> &second){
    vector<int> temp;
    int fir=0, sec=0;
    stack<int, vector<int>> stk1, stk2;
    for(int i=first.size()-1; i>=0; i--){
        stk1.push(first[i]);
    }
    for(int i=second.size()-1; i>=0; i--){
        stk2.push(second[i]);
    }
    while(!stk1.top()==0 || !stk2.top()==0){
        if(stk1.top()==0){
            temp.push_back(stk2.top());
            stk2.pop();
        }
        else if(stk2.top()==0){
            temp.push_back(stk1.top());
            stk1.pop();
        }
        else{
            if(stk1.top()>=stk2.top()){
                temp.push_back(stk2.top());
                stk2.pop();
            }         
            else{
                temp.push_back(stk1.top());
                stk1.pop();
            }
        }
    }
    return temp;
}

vector<int> mergesort(vector<int> &arr, int low, int high){
    vector<int> special;
    if(low<high){
        int mid = (low+high)/2;
        vector<int> ran1 = mergesort(arr, low, mid);
        vector<int> ran2 = mergesort(arr, mid+1, high);
        special = recombine(ran1, ran2);
        return special;
    }
    else{
        if(low == high){
            vector<int> ret;
            ret.push_back(arr[low]);
            return ret;
        }
    }
}

int main(){
    cout<<"Merge sort (0 is ignored)"<<endl;
    cout<<"Enter no. of elements to sort:"<<endl;
    int count;
    cin>>count;
    vector<int> temp;
    for(int i=0; i<count; i++){
        int some;
        cin>>some;
        temp.push_back(some);
    }
    temp = mergesort(temp, 0, temp.size());
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
}