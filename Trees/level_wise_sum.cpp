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

template<typename T>
class ListNode{
public:
    T object;
    ListNode* next;
    ListNode(T val) : object(val), next(NULL) {}
};

template<typename T>
class Queue{
public:
    ListNode<T> *head, *tail;
    Queue() : head(NULL), tail(NULL) {}
    void Enqueue(T val){
        ListNode<T> *n = new ListNode<T>(val);
        if(head == NULL && tail == NULL) head = tail = n;
        else{
            tail->next = n;
            tail = n;
        }
    }
    T Dequeue(){
        ListNode<T>* t = head;
        if(!head && !tail){
            t->object = NULL;
        }else if(head == tail){
            head = tail = NULL;
        }else{
            head = head->next;
        }
        return t->object;
    }
    bool isEmpty(){
        if(!head && !tail) return true;
        return false;
    }
    ~Queue(){
        while(head){
            ListNode<T> *temp = head;
            head = head->next;
            delete head;
        }
    }
};

int main()
{
    vector<int> pre = {1,5,2,3,10,4,5};
    vector<int> in = {2,5,3,1,4,10,5};
    Node* tree = buildTree(pre, in, 0, pre.size()-1);  
    Queue<Node*> q;
    q.Enqueue(tree);
    q.Enqueue(NULL);
    vector<int> levelsum;
    int sum = 0;
    while(!q.isEmpty()){
        Node *t = q.Dequeue();
        if(!t){
            levelsum.push_back(sum);
            sum = 0;
            if(!q.isEmpty())        //Important
                q.Enqueue(NULL);
        }else{
            sum+=t->data;
            if(t->lchild) q.Enqueue(t->lchild);
            if(t->rchild) q.Enqueue(t->rchild);
        }
    }
    for(auto x: levelsum) cout << x << '\n';

    return 0;
}
