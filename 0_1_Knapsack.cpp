#include<bits/stdc++.h>
using namespace std;


int knapsack(int w[], int v[], int n, int W, vector<vector<int>> &arr){
    if(arr[n][W] != -1) return arr[n][W];
    int ans;
    if(n==0 || W == 0) ans = 0;
    else if(w[n-1] <= W)
        ans = max(v[n-1] + knapsack(w,v,n-1,max(0, W-w[n-1]), arr), knapsack(w,v,n-1,W, arr));
    else 
        ans = knapsack(w,v,n-1,W, arr);
    return arr[n][W] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int W, n;
        cin >> W >> n;
        int w[n], value[n];
        int weigh,val;
        vector<vector<int>> arr(n+1, vector<int> (W+1,-1));
        for(int i=0;i<n;i++){
            cin >> weigh >> val;
            w[i] = weigh;
            value[i] = val; 
        }
#if 0
        //Recursive + Memoized
        knapsack(w,value, n,W, arr);
#else
        //Top Down iterarive
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(i==0 || j==0) arr[i][j] = 0;
                else{
                    if(w[i-1] <= j){
                        arr[i][j] = max(arr[i-1][j], value[i-1] + arr[i-1][max(0,j-w[i-1])]);
                    }else{
                        arr[i][j] = arr[i-1][j];
                    }
                }
            }
        }
#endif

        cout << arr[n][W] << '\n';


    }
    
    return 0;
}