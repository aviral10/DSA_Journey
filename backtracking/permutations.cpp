/*
Author: Aviral
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Permutaions of a vector using simple backtracking.


template<typename T=int>
void subsets(vector<T> &a, int ind=0)
{
    static vector<T> res;
    if(ind == a.size())
    {
        cout << "{";
        for(auto x: res)
            cout << x << " ";
        cout << "}\n";
    }
    else
    {
        subsets(a, ind+1);
        res.push_back(a[ind]);
        subsets(a, ind+1);
        res.pop_back();
    }

}

template<typename T=int>
void perm1(vector<T> &a, int l, int h)
{
    if(l==h)
    {
        for(auto x: a)
            cout << x << " ";
        cout << '\n';
    }
    else
    {
        for(int i=l;i<=h;i++)
        {
            swap(a[l], a[i]);
            perm1<T>(a, l+1, h);
            swap(a[l], a[i]);
        }
    }
}

template<typename T=int>
void perm2(vector<T> &a, int k)
{
    static vector<T> res(a.size());
    static vector<int> mark(a.size());
    if(k==a.size())
    {
        for(auto x: res)
            cout << x << ' ';
        cout << '\n';
    }
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if(mark[i] == 0)
            {
                mark[i] = 1;
                res[k] = a[i];
                perm2<T>(a, k+1);
                mark[i] = 0;
            }
        }
    }
}

vector<char> string_to_vector(string &a)
{
    vector<char> res;
    for(auto x: a)
    {
        res.push_back(x);
    }
    return res;
}

int main()
{
    vector<int> a = {1,2,3};
    vector<char> b;
    string p = "abc";
    b = string_to_vector(p);
    subsets(a, 0);
    perm1<char>(b, 0, b.size()-1);
    perm2<char>(b, 0);
    
    perm2(a, 0);
    cout << '\n';
    perm1(a, 0, a.size()-1);
    
    cout << '\n';
    return 0;
}
