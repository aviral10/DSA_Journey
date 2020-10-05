/*
Author: Aviral
*/

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class BinarySearchTree{
public:
    Node* root;
    BinarySearchTree()        { root = NULL; }
    BinarySearchTree(Node* r) { root = r; }
private:
    Node* insert(Node* root, int val){
        if(root == NULL){
            Node* n = new Node();
            n->data = val;
            n->lchild = NULL;
            n->rchild = NULL;
            return n;
        }
        if(val < root->data){
            root->lchild = insert(root->lchild, val);
        }else if(val > root->data){
            root->rchild = insert(root->rchild, val);
        }
        return root;
    }

    int inorder_successor(Node* root){
        Node* t = root;
        while(t->lchild){
            t = t->lchild;
        }
        return t->data;
    }

    Node* Delete(Node* root, int val){
        if(root == NULL) return root;
        if     (val < root->data) root->lchild = Delete(root->lchild, val);
        else if(val > root->data) root->rchild = Delete(root->rchild, val);
        else{
            //Case 1: No child
            if(root->lchild == NULL && root->rchild == NULL){
                delete root;
                root = NULL;
                return root;
            }
            //Case 2: Exactly 1 child
            if(root->lchild == NULL){
                Node* t = root;
                delete t;
                root = root->rchild;
                return root;
            }else if(root->rchild == NULL){
                Node* t = root;
                delete t;
                root = root->lchild;
                return root;
            }
            //Case 3: Two child
            root->data = inorder_successor(root->rchild);
            Delete(root->rchild, root->data);
            return root;
        }
    }

    void inorder(Node* r){
        if(r==NULL) return;
        inorder(r->lchild);
        cout << r->data << ' ';
        inorder(r->rchild);
    }

    void deleteBinarySearchTree(Node* root){
        if(root == NULL) return;
        deleteBinarySearchTree(root->lchild);
        deleteBinarySearchTree(root->rchild);
        delete root;
    }
public:
    void insert(int val){
        root = insert(this->root, val);
    }

    void Delete(int val){
        root = Delete(root, val);
    }

    void inorder(){
        inorder(this->root);
        cout << '\n';
    }

    ~BinarySearchTree(){
        deleteBinarySearchTree(this->root);
    };
};

int main(){
    BinarySearchTree b;
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(5);
    b.insert(15);
    b.insert(25);
    b.insert(35);
    b.inorder();
    b.Delete(20);
    b.inorder();
    return 0;
}
