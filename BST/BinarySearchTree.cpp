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
    b.insert(10);
    b.insert(-10);
    b.insert(20);
    b.insert(-20);
    b.insert(-15);
    b.inorder();
    return 0;
}
