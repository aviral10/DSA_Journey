/*
Author: Aviral
*/
#include <bits/stdc++.h>
using namespace std;

//Basic implemenration of Dijktra's Shortest path algorithm.

template<class T>
class Graph
{
public:
    T graph;
    int size;
};

typedef pair<int,int> pii;
typedef pair<int, char> pic;

template<typename T=vector<vector<pii>>, typename U=pii>
vector<pii> dijkstras(Graph<T> g, int s)
{
    priority_queue<U,vector<U>, greater<U>> q;
    static vector<int> visited(g.size+1);
    static vector<U> distance(g.size+1,{INT_MAX, -1});
    q.push({0, s});
    
    distance[s] = {0,0};
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(!visited[u])
        {
            visited[u] = 1;
            for(auto x : g.graph[u])
            {
                int b = x.first;
                int w = x.second;
                if(distance[u].first +w < distance[b].first)
                {
                    distance[b].first = distance[u].first + w;
                    distance[b].second = u;
                    q.push({distance[b].first, b});
                }
            }
        }
    }
    return distance;
}

template<typename T=pii, typename U=int>
void path(vector<T> &d, int end)
{
    //assuming that start = 1
    vector<U> p;
    if(d[end].first != INT_MAX)
    {
        
        p.push_back(end);
        end = d[end].second;
        do
        {
            p.push_back(end);
            end = d[end].second;
        } while(end != 1);
        p.push_back(1);
    
        cout << "Path: \n";
        for(auto it = p.rbegin();it!=p.rend();it++)
            cout << *it << "-";
        cout << "\b \n";
    }
}

int main()
{
    typedef vector<vector<pii>> type;

    Graph<type> g;
    //graph contains {b,w} for row that denotes: node "row" connected to b via weight w
    g.graph = { {{-1,-1}},
                {{2,7},{3,2},{5,3}},
                {{1,7},{3,3}, {4,4}},
                {{1,2},{2,3},{4,4},{6,1}},
                {{2,4},{3,4},{7,5}},
                {{1,3},{13,2}},
                {{3,1},{7,3},{8,2}},
                {{4,5},{6,3}},
                {{6,2},{9,2}},
                {{8,2},{10,5}},
                {{9,5},{11,4},{12,4}},
                {{10,4},{12,6},{13,4}},
                {{10,4},{11,6},{13,4}},
                {{11,4},{12,4},{5,2}}   };
    g.size = 13;
    vector<pii> dist;
    
    int end = 2;


    dist = dijkstras<type, pii>(g, 1);
    
    
    path<pii, int>(dist, end);
    
    cout << "Total: " << dist[end].first << '\n';

}
