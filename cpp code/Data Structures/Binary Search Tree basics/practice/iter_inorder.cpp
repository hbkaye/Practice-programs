#include<iostream>
#include<stack>

using namespace std;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node * insert(struct node *root, int key){
    if(root == NULL){
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node *));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else if(key < root->data){
        root->lchild = insert(root->lchild, key);
    }
    else if(key > root->data){
        root->rchild = insert(root->rchild, key);
    }
    return root;
}

void iter_inorder(struct node *root){
    stack<struct node *> stk;
    struct node *p = root;
    do{
        if(p->lchild!=NULL && p->rchild!=NULL){
            stk.push(p->rchild);
            stk.push(p);
            p = p->lchild;
        }
        else if(p->rchild == NULL && p->lchild){
            stk.push(p);
            p = p->lchild;
        }
        else if(p->lchild == NULL && p->rchild){
            cout << p->data << endl;
            p = p->rchild;
        }
        else{
            stk.push(p);
            while(stk.size() > 1){
                cout << stk.top()->data << endl;
                stk.pop();
                p = stk.top();
            }
            if(p->lchild == NULL && p->rchild == NULL){
                cout << p->data << endl;
                break;
            }
            else if(p->lchild)
        }
    }while(!stk.empty());
}

int main(){
    struct node *root = NULL;
    int input;
    cin >> input;
    do{
        root = insert(root, input);
        cin >> input;
    }while(input != 0);
    iter_inorder(root);
}


