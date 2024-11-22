/*
code by Subrata Mondal
*/
#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

vector<list<int> > g;

void topologicalSort(int v) {
    vector<bool> visited(v, false);
    vector<int> indegree(v, 0);
    for(auto i : g) {
        for(auto v : i){
            indegree[v]++;
        }
    }
    queue<int> qu;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0){
            qu.push(i);
            visited[i]=true;
        }
    }
    while(not qu.empty()) {
        auto node = qu.front();
        qu.pop();
        cout<<node<<" ";
        for(auto neigh: g[node]) {
            if(!visited[neigh]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    qu.push(neigh);
                    visited[neigh]=true;
                }
            }
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    g.resize(n, list<int> ());
    int m;
    cin>>m;
    while(m--) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    topologicalSort(n);
    return 0;
}
