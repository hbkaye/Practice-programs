#include <iostream>
#include <cstdlib>
#include "implementation.h"
using namespace std;


int main() {
    int x;
    cout<<"Type no. of entries to push:"<<endl;
    cin>>x;
    queue q;
    while(x--){
        int temp;
        cin>>temp;
        q.pushBack(temp);
    }
    cout<<"Type no. of entries to pop:"<<endl;
    cin>>x;
    while(x--){
        cout<<(q.getFront())<<endl;
        q.popFront();
    }
    cout<<"Final size of queue is: "<<q.size()<<endl;
    return 0;
}