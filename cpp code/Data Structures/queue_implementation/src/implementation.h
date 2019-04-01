#ifndef _IMPLEMENTATION_H_
#define _IMPLEMENTATION_H_
#include <iostream>
using namespace std;
class queue{
    public:
    queue(){
    first = NULL;
    last = NULL;
    count = 0;
    };
    void pushBack(int item);
    void popFront();
    int getFront();
    bool isEmpty();
    int size();
    
    private:
    struct newNode{
        int data;
        newNode* next = NULL;
    };
    newNode *first, *last;
    int count;
};
bool queue::isEmpty(){
    return count==0;
}
int queue::size(){
    return count;
}
void queue::pushBack(int item){
    if(isEmpty()){
        newNode *temp = (newNode* )malloc(sizeof(newNode));
        temp->data = item;
        temp->next = NULL;
        last = first = temp;
    }
    else{
        newNode* temp = (newNode*)malloc(sizeof(newNode));
        temp->data = item;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    count++;
}
int queue::getFront(){
    return first->data;
}
void queue::popFront(){
    if(isEmpty()){
        cout<<"QUEUE IS EMPTY!"<<endl;
    }
    else{
        first = first->next;
        count--;
        if(isEmpty()){
            last = first;
        }
    }
}
#endif