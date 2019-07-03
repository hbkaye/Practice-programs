#include <iostream>
#include <vector>

using namespace std;

struct node{
        int data;
        node *next;
    };

node *newNode(){
    node * temp;
    temp = (node *)malloc(sizeof(node *));
    temp->data = 0;
    temp->next = NULL;
    return temp;
}

int func(int input){
    int temp = input%10;
    return temp;
}

void insert(node *temp, int indata){
    node *cache = newNode();
    cache->data = indata;
    cache->next = temp->next;
    temp->next = cache;
    return;
}

node *insertList(node *ptr, int indata){
    if(ptr->next == NULL){
        ptr->next = newNode();
        ptr->next->data = indata;
        return ptr;
    }
    node *temp = ptr;
    while(temp->next != NULL){
        if(temp->next->data >= indata){
            insert(temp, indata);
            return ptr;
        }
        else temp = temp->next;
    }
    return ptr;
}

void insertHash(vector<node *> hashtable, int indata){
    int temp = func(indata);
    hashtable[temp] = insertList(hashtable[temp], indata);
    return;
}

int main(){

    vector<node *> hashtable(10, NULL);
    int input =0, temp = 0;
    for(int i = 0; i<10; i++){
        hashtable[i] = newNode();
    }
    insertHash(hashtable, 53);
    insertHash(hashtable, 0);
    insertHash(hashtable, 1);
    insertHash(hashtable, 2);
    insertHash(hashtable, 3);
    insertHash(hashtable, 4);
    insertHash(hashtable, 5);
    insertHash(hashtable, 6);
    insertHash(hashtable, 7);
    insertHash(hashtable, 8);
    insertHash(hashtable, 9);
    for(int i=1; i<10; i++){
        cout << hashtable[i]->next->data << endl;
    }
    cout << hashtable[3]->next->next->data << endl;
}