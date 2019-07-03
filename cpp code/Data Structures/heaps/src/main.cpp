#include <iostream>
#include <vector>
using namespace std;

void max_heapify (vector<int> &Arr, int i, int N)
{
    int left = 2*i;           
    int right = 2*i +1;
    int largest;          
    if(left<= N and Arr[left] > Arr[i] )
          largest = left;
    else
         largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    } 
 }
 void build_maxheap (vector<int> &Arr)
{
    for(int i = Arr.size()/2 ; i >= 0 ; i-- )
    {
        cout<<i<<endl;
        max_heapify (Arr, i, Arr.size()) ;
    }
}
int main(){
    vector<int> temp{ 3,5,6,5,43,4,5,566,54,3,32,0,2344574, 8876, 8765,8909,1,0};
    cout<<temp.size()<<endl;

    build_maxheap(temp);
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
}