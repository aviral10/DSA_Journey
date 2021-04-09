/*
	Author: Aviral
	Sample Problem link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


// nlogn solution
void longestIncreasingSubsequence_nlogn(vector<int> &arr){
	unordered_map<int,int> mp;
	vector<int> lis;
	lis.push_back(arr[0]);
	mp[arr[0]] = INT_MIN;
	for(int i=1;i<arr.size();i++){
		if(arr[i] > lis.back()){
			lis.push_back(arr[i]);
			mp[arr[i]] = lis[lis.size()-2];

		}else{
			int idx = lower_bound(lis.begin(), lis.end(), arr[i])-lis.begin();
			lis[idx] = arr[i];
			mp[lis[idx]] = lis[((idx-1<0)?INT_MIN:idx-1)];
		}
	}
	
	vector<int> seq;
	int want = lis.back();
	while(want != INT_MIN){
		seq.push_back(want);
		want = mp[want];		
	}
	cout << "Length of longest increasing subsequence: " <<lis.size() << '\n';
	for(int i=seq.size()-1;i>=0;i--){
		cout << seq[i] << ' ';
	}
	cout << '\n';
}

// n^2 solution
void longestIncreasingSubsequence_n2(vector<int> &arr){
	unordered_map<int,int> mp;
	mp[arr[0]] = INT_MIN;
	vector<int> lis(arr.size(), 1);
	int max_val = 1, max_idx=0;
	for(int i=1;i<arr.size();i++){
		int mx = 1, mdx = i;
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] and lis[j] >= mx){
				mx = lis[j];
				mdx = j;
			}			
		}
		lis[i] += (mdx == i?0:lis[mdx]);
		if(lis[i] > max_val){
			max_val = lis[i];
			max_idx = i;
		}		
		mp[arr[i]] = arr[mdx];
	}

	vector<int> seq;
	int want = arr[max_idx];
	while(want != INT_MIN){
		seq.push_back(want);
		want = mp[want];		
	}
	cout << "Length of longest increasing subsequence: " << seq.size() << '\n';
	for(int i=seq.size()-1;i>=0;i--){
		cout << seq[i] << ' ';
	}
	cout << '\n';
}

// nlogn + n^2 solution using Longest common subsequence
void longestIncreasingSubsequence_usingLCS(vector<int> &arr){
	set<int> st;
	for(int x: arr){
		st.insert(x);
	}
	vector<int> arr2;
	for(auto x: st){
		arr2.push_back(x);
	}
	int dp[arr.size()+1][arr2.size()+1];
	int mx = 0;
	for(int i=0;i<=arr.size();i++){
		for(int j=0;j<=arr2.size();j++){
			if(i==0 or j == 0){
				dp[i][j] = 0;
			}else{
				if(arr[i-1] == arr2[j-1]){
					dp[i][j] = 1+dp[i-1][j-1];
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
				mx = max(mx, dp[i][j]);
			}
		}
	}

	vector<int> seq;
	int i=arr.size(), j = arr2.size();
	while(i > 0 and j > 0){
		if(arr[i-1] == arr2[j-1]){
			seq.push_back(arr[i-1]);
			i--;j--;
		}else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}

	cout << "Length of longest increasing subsequence: " << seq.size() << '\n';
	for(int i=seq.size()-1;i>=0;i--){
		cout <<seq[i] << ' ';
	}
	cout << '\n';
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

	vector<int> arr = {2,5,3,7,11,8,10,13,6};
	// vector<int> arr = {10,22,9,33,21,50,41,60,50,1};
	longestIncreasingSubsequence_n2(arr);
	longestIncreasingSubsequence_nlogn(arr);
	longestIncreasingSubsequence_usingLCS(arr);	
	
	
	return 0;
}