/*
Author: Aviral
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int partition(vector<int> &a, int l, int h){
    int pivot = l;
    int i=l,j=h;
    while(i<j)
    {
        while(a[i] <= a[pivot] && i < a.size())
        {
            i++;
        }
        while(a[j] > a[pivot] && j >= 0)
        {
            j--;
        }
        if(i<j)
            swap(a[i], a[j]);
    }
    swap(a[pivot], a[j]);
    return j;
}

void quicksort(vector<int> &a, int l, int h){
    int pi;
    if(l <= h)
    {
        pi = partition(a, l, h);
        quicksort(a, l, pi-1);
        quicksort(a, pi+1, h);
    }
}

void merge(vector<int> &a, int l, int div, int h)
{
    int i=l, j=div+1;
    vector<int> arr;
    while(i!=div+1 && j!=h+1)
    {
        if(a[i] < a[j])
        {
            arr.push_back(a[i++]);
        }
        else
        {
            arr.push_back(a[j++]);
        }
    }
    while(i!=div+1)
        arr.push_back(a[i++]);
    while (j!=h+1)
        arr.push_back(a[j++]);
    a = arr;
}

void mergesort(vector<int> &a, int l, int h)
{
    int mid = (l+h)/2;
    if(l<h)
    {
        mergesort(a, 0, mid);
        mergesort(a,mid+1, h);
        merge(a, 0, mid, h);
    }

}


int main()
{
    vector<int> a = {4,9,7,5,8,10,-3};
    quicksort(a, 0, a.size()-1);
    for(auto x: a)
    {
        cout << x << ' ';
    }
    cout << "\n";
    mergesort(a, 0, a.size()-1);
    for(auto x: a)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
