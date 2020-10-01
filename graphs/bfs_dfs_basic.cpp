/*
Author: Aviral
*/

#include<bits/stdc++.h>
using namespace std;

//Basic implementation of BFS and DFS for a graph that uses a adjacency list.

void bfs(vector<vector<int>> &a, int u)
{
    static vector<int> visited(a.size());
    static queue<int> q;
    q.push(u);
    visited[u] = 1;
    cout << u << ' ';
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(auto x : a[s])
        {
            if(!visited[x])
            {
                visited[x] = 1;
                cout << x << ' ';
                q.push(x);
            }
        }
    }
}

void dfs(vector<vector<int>> &a, int u)
{
    static vector<int> visited(a.size());
    if(!visited[u])
    {
        visited[u] = 1;
        cout << u << ' ';
        for(auto x : a[u])
        {
            dfs(a, x);
        }
    }
}

int main()
{
    vector<vector<int>> a = {{1,2},{3,4},{5,6},{},{},{},{}};
    cout << "Dfs: \n";
    dfs(a, 0);
    cout << "\n";
    cout << "Bfs: \n";
    bfs(a, 0);
    cout << '\n';
    return 0;
}
