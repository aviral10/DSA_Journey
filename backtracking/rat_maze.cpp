#include<bits/stdc++.h>

using namespace std;

//Easiest Rat maze problem, possible moves: down or right, starts form 0,0 end at n-1,n-1

void print_board(vector<vector<int>> &a)
{
    for(auto x : a)
    {
        for(auto p : x)
            cout << p << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int solve(vector<vector<int>> &a, pair<int, int> start, pair<int,int> end)
{
    if(a[start.first][start.second] != 0)
        return -1;
    a[start.first][start.second] = 1;
    vector<pair<int,int>> moves = {{0,1}, {1,0}};
    static int count = 0, found = 0;
    if(start == end)
    {
        count++;
        found = 1;
        cout << "Total solutions: " << count <<'\n';
        print_board(a);
        return 1;
    }
    else
    {
        for(auto x : moves)
        {
            int coi = start.first+x.first;
            int coj = start.second+x.second;
        
            if((coi < a.size() && coj < a[0].size()) && a[coi][coj] == 0)
            {
                start.first  += x.first;
                start.second += x.second; 
                //a[start.first][start.second] = 1;

                solve(a, start, end);
                
                a[start.first][start.second] = 0;
                start.first -= x.first;
                start.second -= x.second;
            }
        }
    }
    if(!found)
        return -1;
}

int main()
{
    vector<vector<int>> board = {{0,0,0,0,0},
                                 {0,8,8,0,0},
                                 {0,0,0,8,0},
                                 {0,8,8,0,0},
                                 {0,0,0,0,0}};
    int n = board.size();
    int x = solve(board, {0,0}, {n-1,n-1});
    if(x == -1)
        cout << "No Solutions possible\n";

    return 0;
}
