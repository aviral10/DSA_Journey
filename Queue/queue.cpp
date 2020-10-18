/*
Author : Aviral
*/

// A templatized Queue
#include<bits/stdc++.h>
using namespace std;

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

int main(){
    Queue<int> q;
    int y = 10;
    q.Enqueue(12);
    y = q.head->object;
    return 0;
}