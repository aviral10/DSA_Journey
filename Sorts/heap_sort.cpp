/*
Author: Aviral
*/

#include<bits/stdc++.h>
using namespace std;

//Heap Sort, only works for arrays containing unique elements

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
    vector<int> arr = {1,9,4,5,2,7,-3};
    vector<int> f;
    for(auto x : arr)
    {
        h.Insert(x);
    }
    int i = h.size;
    while(i--)
    {
        f.push_back(h.Delete());
        cout << f.back() << ' ';
    }
    cout << '\n';
}
