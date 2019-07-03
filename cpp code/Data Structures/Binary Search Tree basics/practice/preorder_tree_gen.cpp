#include<iostream>
#include<stack>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *newnode(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    cout << "assigned" << endl;
    return temp;
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
    cout << "Enter elements of array";
    vector<int> input;
    int i = 1;
    while(i++){
        int temp;
        cin >> temp;
        if (temp!=0) input.push_back(temp);
        else break;
    }
    stack <struct node *> stk;
    struct node *temp, *root, *p;
    root = newnode();
    root->data = input[0];
    root->lchild = NULL;
    root->rchild = NULL;
    temp = root;
    for(int j=1; j<i; j++){
        if(input[j] < temp->data){
            stk.push(temp);
            p = newnode();
            p->data = input[j];
            temp->lchild = p;
            temp = p;
        }
        else{
            if(input[j] < stk.top()->data){
                p = newnode();
                p->data = input[j];
                temp->rchild = p;
                temp = p;
            }
            else if(input[j] > stk.top()->data){
                temp = stk.top();
                stk.pop();
                j--;
            }
        }
    }
    levelOrder(root);
}