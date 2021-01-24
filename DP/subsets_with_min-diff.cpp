/*
Author: Aviral
Sample problem link: https://www.interviewbit.com/problems/minimum-difference-subsets/
*/

int Solution::solve(vector<int> &arr) {
    int n=arr.size();
    int s = 0,hs = 0;
    for(auto x: arr){
        s += x;
    }
    hs = s;
    s = ceil(s/2.0);
    vector<vector<bool>> dp(n+1, vector<bool> (s+1, false));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i == 0 or j == 0){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }else{
                dp[i][j] = dp[i-1][j] or (dp[i-1][max(0, j-arr[i-1])] or arr[i-1]==j)?true:false;
            }
            
        }
    }
    bool val = dp[n][s];
    int left = s;
    while(val == false and s >= 0){
        val = dp[n][--s];
    }
    return abs(hs-s-s);
}