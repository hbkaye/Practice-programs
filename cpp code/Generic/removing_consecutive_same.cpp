#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;
    string::iterator ip;
    ip = unique(str.begin(), str.begin() + str.size());
    str.resize(distance(str.begin(), ip));
    cout<<str<<endl;
    return 0;
}