/*
Author: Aviral
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Basic Stack
template<typename T>
class Stack{
public:
    vector<T> stack;
    int top;
    Stack() : top(-1) {}

    void push(T val){
        stack.push_back(val);
        top++;
    }

    bool isEmpty() { return top == -1; }

    int pop(){
        if(isEmpty()) return -1;
    
        T temp = stack[top--];
        stack.pop_back();
        return temp;
    }

};


int main()
{
    Stack<int> s;
    cout << s.isEmpty();
    return 0;
}
