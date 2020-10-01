/*
Author: Aviral
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<int>		vi;

//Basic Stack

class Stack{
    public:
        vector<int> stack;
        int top;
        Stack()
        {
            top = -1;
        }

        void push(int val)
        {
            stack.push_back(val);
            top++;
        }

        int isEmpty()
        {
            return top == -1;
        }

        int pop()
        {
            if(isEmpty())
                return -1;
            int temp;
            temp = stack[top--];
            stack.pop_back();
            return temp;
        }

};



int main()
{
    
    return 0;
}
