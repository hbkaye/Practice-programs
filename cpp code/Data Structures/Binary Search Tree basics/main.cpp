/*
This code contains:

    Level Order
    Inorder
    Insert(recursive)
    LeafNode
    Delete(recursive)

*/

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

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

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
    return;
}

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

struct node * rightmost(struct node *root){
    struct node *temp;
    while(temp != NULL){
        temp = temp->rchild;
    }
    return temp;
}

bool leafNode(struct node *root){
    if(root->lchild || root->rchild){
        return false;
    }
    return true;
}

void deleteNode(struct  node *root, int indata){
    struct node *temp;
    if(root == NULL){
        return;
    }
    if(leafNode(root)){
        free(root);
        return;
    }
    cout << "not leaf" << endl;
    if(indata  > root->data){
        deleteNode(root->rchild, indata);
        return;
    }
    else if(indata < root-> data){
        deleteNode(root->lchild, indata);
        return;
    }
    else{
        cout << "O yeah!" << endl;
        temp = rightmost(root->lchild);
        cout << temp->data << endl;
        root->data = temp->data;
        deleteNode(temp, temp->data);
    }
}

int main(){
    struct node *root = NULL;
    int input;
    cin >> input;
    do{
        root = insert(root, input);
        cin >> input;
    }while(input != -1);
    levelOrder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    deleteNode(root, 12);
    inorder(root);
}