/*
Author: Aviral
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Kadane's algorithm for finding the subarray with maximum sum
int max_sum_array(vector<int> &a)
{
    int sum = 0, best = 0;
    for(int i=0;i<a.size();i++)
    {
        sum = max(a[i], sum+a[i]);
        best = max(best, sum);
    }
    return best;
}


int main()
{
    vector<int> arr = {-1,2,4,-3,5,2,-5,2};
    int val;
    val = max_sum_array(arr);
    cout << val << '\n';
    
    return 0;
}
