/*
code by Subrata Mondal
*/
#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
unordered_set<int> visited;
vector<vector<int> > result;
int v; // no of vertices
void add_edge(int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

void dfs(int curr, int end, vector<int> &path) {
    if(curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // mark visited
    path.push_back(curr);
    for(auto neighbour: graph[curr]) {
        if(not visited.count(neighbour)) {
           
            dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src, int dest) {
    vector<int> v;
    dfs(src, dest, v);
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
    int x, y;
    cin>>x>>y;
    allPath(x, y);
    for(auto path: result) {
        for(auto el : path) {
            cout<<el<<" ";
        }
    
        cout<<"\n";
    }
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