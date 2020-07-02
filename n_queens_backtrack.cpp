#include<bits/stdc++.h>
#define ll long long
using namespace std;


//N queens problem, uses backtracking(Easy)

void print_board(vector<vector<int>> &board)
{
    for(auto x: board)
    {
        for(auto p : x)
            cout << p << ' ';
        cout << "\n";
    }
    cout<< "\n";
}

//prints solution board
void print_final_board(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            if(j == a[i])
            {
                cout << 1 << ' ';
            }
            else
            {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    cout << "\n";
}

void eatup(vector<vector<int>> &a, int row, int col ,int val)
{
    int i=row,j;
    //left diagonal
    for(j=col;j>=0 && i < a.size();j--)
        a[i++][j] += val;
    //right diagonal
    i = row;
    for(j = col;j<a.size() && i<a.size(); j++)
        a[i++][j] += val;
    i = row;
    j = col;
    //column
    for(j=col;i<a.size();i++)
        a[i][j] += val;
}


void Nqueens(vector<vector<int>> &a, int k)
{
    static int count = 0;
    static vector<int> ans;
    if(k==a.size())
    {
        count++;
        cout << "Count: " << count << '\n';
        for(auto x: ans)
            cout << x << ' ';
        cout << "\n\n";
        print_final_board(ans);
        
        return;
    }
    for(int j=0;j<a.size();j++)
    {
        if(!a[k][j])              //real cheese, just 6 lines (or 3)
        {
            eatup(a, k, j, 1);
            ans.push_back(j);
            
            Nqueens(a, k+1);        
            
            eatup(a, k, j, -1);
            ans.pop_back();
        }
    }
}



int main()
{
    vector<vector<int>> board;
    int N = 4;
    //initialize the board
    for(int i=0;i<N;i++)
    {
        vector<int> t(N);
        board.push_back(t);
    }
    //call Nqueens on 0th index
    Nqueens(board, 0);
    
    return 0;
}


/*
Sample output: 
Count: 1
1 3 0 2 

0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

Count: 2
2 0 3 1 

0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 

*/
