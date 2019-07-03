/*
This code contains :
    levelorder
    create binary tree(queue)
    iterative traversal(stack)
    find a no. (recursive)

*/
#include <iostream>
#include <queue>
#include <string>
#include <stack>

using namespace std;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};
int count = 0;

void createBin(struct node *ptr){
    queue <struct node *> q;
    ptr->lchild = NULL;
    ptr->rchild = NULL;
    q.push(ptr);
    int input = 0;
    while(!q.empty()){
        cout << "Enter if left child or else -1" << endl;
        cin >> input;
        if(input != -1){
            struct node *newNode = (struct node *) malloc (sizeof(struct node *));
            q.front()->lchild = newNode;
            newNode->lchild = NULL;
            newNode->data = input;
            newNode->rchild = NULL;
            q.push(newNode);
        }
        cout << "Enter if right child or else -1" << endl;
        cin >> input;
        if(input != -1){
            struct node *newNode = (struct node *) malloc (sizeof(struct node *));
            q.front()->rchild = newNode;
            newNode->lchild = NULL;
            newNode->data = input;
            newNode->rchild = NULL;
            q.push(newNode);
        }
        q.pop();
    }
}

//inorder

bool findNumber(int indata, struct node *ptr1){
    cout << "Element being checked is -->" << ptr1->data << endl;
    if(ptr1->data == indata){
        cout << "No. is found!" << endl;
        return true;
    }
    else cout << "Not matched !" << endl;
    if(ptr1->lchild != NULL){
        cout << "Checking element at its --> left" << endl;
        if(findNumber(indata, ptr1->lchild)) return true;
    }
    if(ptr1->rchild != NULL){
        cout << "Checking element at --> right" << endl;
        if(findNumber(indata, ptr1->rchild)) return true;
    }
    return false;
}
void iterTreeTrav(struct node *ptr){
    stack<struct node *> stk;
    struct node *temp;
    temp = ptr;
    do{
        if(temp){
            cout << temp->data << " ";
            stk.push(temp);
            temp  = temp->lchild;
        }
        else{
            temp = stk.top()->rchild;
            stk.pop();
        }
    }while(temp || !stk.empty());
}
void levelOrder(struct node *ptr){
    queue<struct node *> q;
    struct node *temp;
    q.push(ptr);
    cout << ptr->data << " ";
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->lchild){
            q.push(temp->lchild);
            cout << temp->lchild->data << " ";
        }
        else cout << "#" << " ";
        if(temp->rchild){
            q.push(temp->rchild);
            cout << temp->rchild->data << " ";
        }
        else cout << "#" << " ";
    }
}

int main(){
    struct node *ptr;
    ptr = (struct node *) malloc (sizeof(struct node *));
    cout << "Input root element" << endl;
    cin >> ptr->data;
    createBin(ptr);
    cout << "success" << endl;
    levelOrder(ptr);
}