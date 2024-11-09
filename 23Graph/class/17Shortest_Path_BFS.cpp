/*
code by Subrata Mondal
*/
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
vector<vector<int> > result;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

void bfs(int src, vector<int> &dist) {
    queue<int> qu;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while(not qu.empty()) {
        int curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour : graph[curr]) {
            if(not visited.count(neighbour)) {
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout<<"\n";
}


int main() {
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    int x,y;
    cin>>x>>y;
    vector<int> dist;
    bfs(x, dist);
    for(int i = 0; i < dist.size(); i++) {
        cout<<dist[i]<<" ";
    }

    cout<<"\n shortest path of distnation : "<<dist[y];
    return 0;
}

/*
7
8
0 1
0 4
1 3
1 5
4 3
5 6
5 2
6 2

0 6
*/