/*
Author: Aviral
Sample problem: https://www.spoj.com/problems/EDIST/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Recursive
string a,b;
int solve(vector<vector<int>> &dp, int m, int n){
    if(m == 0) return dp[m][n] = n;
    if(n == 0) return dp[m][n] = m;
    if(dp[m][n] != -1) return dp[m][n];

    if(a[m-1] == b[n-1]) return solve(dp, m-1,n-1);
    
    //Insert in a
    int a = solve(dp, m, n-1)+1;
    
    //Delete in a
    int b = solve(dp, m-1, n)+1;
    
    //Replace in a
    int c = solve(dp, m-1, n-1)+1;
    
    int ans = min(a, min(b,c));
    return dp[m][n] = ans;
}

//Top-down iterative
int TEST_CASES = 1;
void submain(){
    cin >> a  >> b;
    int la = a.size(), lb = b.size();
    vector<vector<int>> dp(la+1, vector<int> (lb+1, -1));
    for(int i=0;i<=la;i++){
        for(int j=0;j<=lb;j++){
            if(i == 0 or j == 0){
                if(i == 0) dp[i][j] = j;
                if(j == 0) dp[i][j] = i;
                continue;
            }

            //Insert
            int x = dp[i][j-1]+1;
            
            //Delete
            int y = dp[i-1][j]+1;
            
            //Replace
            int z = dp[i-1][j-1]+((a[i-1] == b[j-1])?0:1);
            
            dp[i][j] = min(x, min(y,z));
        }
    }    
    cout << dp[la][lb] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    if(TEST_CASES){
        ll t;
        cin >> t;
        while(t--){
            submain();
        }
    }else{
        submain();
    }
	return 0;
}