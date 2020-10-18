/*
Author : Aviral
*/

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int val): data(val), lchild(NULL), rchild(NULL) {}

};
int search(vector<int> &in, int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(in[i] == val)
            return i;
    }
}


Node* buildTree(vector<int> &pre, vector<int> &in, int start, int end){
    static int index = 0;
    if(start > end) return NULL;
    
    Node* t = new Node(pre[index++]);

    //If it is a leaf node
    if(start == end) return t;

    int f_ind = search(in, start, end, t->data);
    t->lchild = buildTree(pre, in, start, f_ind-1);
    t->rchild = buildTree(pre, in, f_ind+1, end);
    return t;
}


//Print the elements inorder before deleting
void delTree(Node *root){
    if(root == NULL) return;
    delTree(root->lchild);
    cout << root->data << ' ';
    delTree(root->rchild);
    delete root;
    root=NULL;
}

int main()
{
    vector<int> pre = {1,2,4,5,6,3};
    vector<int> in = {4,2,5,1,6,3};
    Node* tree = buildTree(pre, in, 0, pre.size()-1);  
    delTree(tree); 
    return 0;
}