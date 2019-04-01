#include <bits/stdc++.h>

using namespace std;

    int partition(vector<int> &arr, int low, int high ){
        int pivot = arr[high];
        int i = low-1;
        for(int j=low; j<=high-1; j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return (i+1);    
    }
    void quicksort(vector<int> &arr, int low, int high){
        if(low<high){ 
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi-1);
            quicksort(arr, pi+1, high);
        }
    }
    int main(){

        cout<<"Quick sort"<<"\n"<<"Enter your no. of integers:"<<endl;
        vector<int> arr;
        int count;
        cin>>count;
        cout<<"\n"<<"Enter integers"<<endl;
        for(int i=0; i<count; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        int low = 0, high = arr.size()-1;
        quicksort(arr, low, high);
        for(int i=0; i<count; i++){
            cout<<arr[i]<<" ";
        }
    }
