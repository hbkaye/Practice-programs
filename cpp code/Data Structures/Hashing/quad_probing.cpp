#include<iostream>
#define SIZE 10

using namespace std;

int hashfunc(int indata){
    return indata%10;
}

int probe(int H[], int key){
    int i = 0;
    while(H[(key + i*i)%SIZE] != 0){
        i++;
    }
    return (key + i*i)%SIZE;
}

void insert(int H[], int indata){
    int key = hashfunc(indata);
    if(H[key] == 0){
        H[key] = indata;
        return;
    }
    key = probe(H, key);
    H[key] = indata;
    return;
}

int main(){
    int H[10] = {0};
    insert(H, 10);
    insert(H, 8);
    insert(H, 9);
    insert(H, 9);
    return 0;
}