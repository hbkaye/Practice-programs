#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int num, sum, count[1000], k=0;
	vector<int> arr;
	stack<int, vector<int>> stk;
	cin >> num;	
	for(int i=0; i<num; i++){
	    cin >> arr[i];
	}
    cout<<"lol"<<endl;
	std::sort(arr[0], arr[num-1], std::greater<int>());
	int mark = arr[0];
	int temp = num;
	while(num--){
	    stk.push(arr[num-1]);
	}cout<<"lol1"<<endl;
	while(temp--){
	    if(mark==stk.top()){
	        count[k]++;
	        stk.pop();
	    }
	    else{
	        k++;
	        mark=stk.top();
	        stk.pop();
	    }
	}
	sum+= count[0]*arr[0];
	for(int i=0; i<=k; i++){
	    if(count[k]<count[k+1]){
	        sum+= (count[k+1]-count[k])*arr[k+count[k]];
	    }
	}
	cout<<sum<<endl;
	return 0;
}
