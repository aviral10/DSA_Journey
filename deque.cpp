#include<bits/stdc++.h>
using namespace std;

//NOT A DOUBLE ENDED QUEUE
//A Basic Deque (Deck), has a maximum length option to restrict the size of queue
//Can be used as a normal queue

template <typename T=int>
struct Node{
    T data;
    struct Node* next;
};

template <typename U=int>
class Deque{
    public:
        struct Node<U>* head;
        struct Node<U>* tail;
        int maxsize;
        int curr;
        Deque(int msize=5)
        {
            maxsize = msize;
            head = tail = NULL;
            curr = 0;
        }
        
        void print_deque()
        {
            struct Node<U>* temp = head;
            while(temp)
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }
            cout << '\n';
        }

        int isEmpty()
        {
            return head == NULL;
        }

        U dequeue()
        {
            U val;
            if(!isEmpty())
            {
                struct Node<U>* temp = head;
                head = head->next;
                val = temp->data;
                delete temp;
                return val;
            }
            else
            {
                cout << "Queue is Empty" <<'\n';
            }
        }
        
        void enqueue(U val)
        {
            struct Node<U>* temp = new struct Node<U>;
            temp->data = val;
            temp->next = NULL;
            if(curr < maxsize)
            {
                if(curr == 0)
                {
                    head = tail = temp;
                    curr++;
                }
                else
                {
                    tail->next = temp;
                    tail = temp;
                    curr++;
                }
            
            }
            else
            {
                dequeue();
                temp = new struct Node<U>;
                temp->data = val;
                temp->next = NULL;                
                tail->next = temp;
                tail = temp;
            }
        }
};


int main()
{
    Deque<int> d(4);
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,20,30,40,50,60};
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        d.enqueue(arr[i]);
        d.print_deque();
    }
    return 0;
}
