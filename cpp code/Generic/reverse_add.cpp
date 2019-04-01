#include <iostream>
using namespace std;
	int length(int y){
        int o = 0;
		for(int g=1; y!=0; g++){
			y = y/10;
			o++;
		}
        return o;
	}
	int joinback(int* tqr, int qq){
		int temp = 0;
		for(int i =1;i<=qq;i++){
			temp = temp*10+tqr[i];
		}
		return temp;
	}
	int* breakdown(int q){
		static int l[10];
        int y = length(q);
		for(int i=1; i<=y; i++){
			l[i] = q%(10);
			q=q/10;
		}
		return l;
	}
	int reverse(int v){
		int p = length(v);
		int* ptr = breakdown(v);
		int reversed = joinback(ptr, p);
		return reversed;
	}

int main() {
	
	int x=0;
	cin>>x;
	for(int i=1;i<=x;i++){
		int temp1, temp2, temp3, temp4, sumrev, sum;
		cin>>temp1>>temp2;
		temp3 = reverse(temp1);
		temp4 = reverse(temp2);
		sumrev = temp3+temp4;
		sum = reverse(sumrev);
        cout<<sum<<"\n";
	}
	return 0;
}
