#include <iostream>
#include <vector>

using namespace std;

void perlocate_down(vector<int> &arr, int index, int size){
    
    int left = index*2, right = index*2+1, temp = arr[index];
    while(left <= size){
        if(arr[left] > arr[right] && arr[index] < arr[left]){
            arr[index] = arr[left];
            index = index*2;
        }
        else if(arr[right] >= arr[left] && arr[index] < arr[right] && right<=size){
            arr[index] = arr[right];
            index = index*2+1;
        }
        else{
            if(arr[index] > arr[left]){break;}
            else{
                swap(arr[index], arr[left]);
                break;
            }
        }
        arr[index] = temp;
        right = index*2+1;
        left = right-1;
    }
}

void build_heap(vector<int> &arr, int size){
    for(int i=size; i>=1; i--){
        perlocate_down(arr, i, size);
    }
}

int main() {
	int num, cache;
	vector<int> temp(num+1);
    cout<<"<--------Starting Heap formation-------->\n"<<"Enter no. of elements: "<<endl;
	cin >> num;
    cout<<"Enter elements:\n";
	for(int i=1; i<=num; i++){
	    cin >> cache;
	    temp[i] = cache;
	}
    build_heap(temp, num);
    for(int i= 1; i<=num; i++){
        cout << temp[i] <<" ";
    }
}
