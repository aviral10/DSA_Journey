/*
Author: Aviral
*/

#include<bits/stdc++.h>
using namespace std;

//Demonstrating heapify recursively.

class Heap{
    public:
        vector<int> heap;
        int size;
        Heap(){size=0;heap.push_back(-1);}

        void Insert(int val)
        {
            heap.push_back(val);
            size++;
            if(size!=1)
            {
                int i = size;
                while(i > 1 && heap[i] > heap[i/2])
                {
                    swap(heap[i], heap[i/2]);
                    i/=2;
                }
            }   
        }
        
        void heapify(int ind)
        {
            int lchild = 2*ind;
            int rchild = 2*ind+1;
            int done = 0;
            if(rchild <= size)
            {
                heapify(rchild);
                int m = lchild;
                done = 1;
                if(heap[rchild] > heap[lchild])
                {
                    m = rchild;  
                }
                if(heap[ind] < heap[m])
                {
                    swap(heap[ind], heap[m]);
                    heapify(m);
                }
                heapify(lchild);
            }
            //The below if statement handles the condition where there might not be a right child
            if(lchild <= size && !done)
            {
                int m = lchild;
                if(heap[ind] < heap[m])
                {
                    swap(heap[ind], heap[m]);
                    heapify(m);
                }
            }
        }
        
        int Delete()
        {
            int t = heap[1];
            heap[1] = heap[size--];
            heap.pop_back();
            int ind=1;
            while(2*ind <= size)
            {
                int lchild = 2*ind;
                int rchild = 2*ind+1;
                int m=lchild;
                int a = 0;
                if(heap[rchild] > heap[lchild])
                {
                    m = rchild;
                    a = 1;
                }
                if(heap[ind] < heap[m])
                {
                    swap(heap[ind], heap[m]);
                }
                else
                    break;
                
                ind = ind*2 + a;
            }
            return t;
        }
};

int main(){
    Heap h;
    //vector<int> arr = {1,3,2,4,5,6};
    vector<int> arr = {1,3,2,4,5,6,7,8,9,11,10,13,12,14};
    vector<int> f;

    //placing non heapified values in the heap-array
    for(auto x : arr)
    {
        h.heap.push_back(x);
    }
    h.size = arr.size();

    h.heapify(1);   //1 represents the root.
    
    //printing the heap(first value is -1, that represents a redundant value to occupy 0th index).
    cout << "Heap: \n";
    for(auto x : h.heap)    
        cout << x << ' ';
    cout << '\n';
    int i = h.size;
    //if the heap is correct, the loop will render values in decending order.
    cout << "Decending order: \n";
    while(i--)
    {
        f.push_back(h.Delete());
        cout << f.back() << ' ';
    }
    cout << '\n';
}
