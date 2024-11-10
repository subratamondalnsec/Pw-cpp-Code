/*
code by Subrata Mondal
problem link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {//dfs method
public:
    // Function to detect cycle in an undirected graph.
    bool cycledetect_dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for (int j : adj[node]) {
            if (j == parent) continue;
            if (visit[j]) return true;
            if (cycledetect_dfs(j, node, adj, visit)) return true;
        }
        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visit(v, false);
        for (int i = 0; i < v; i++) {
            if (!visit[i] && cycledetect_dfs(i, -1, adj, visit)) return true;
        }
        return false;
    }
};


class Solution {//bfs method
  public:
    // Function to detect cycle in an undirected graph.
    bool cycledetect_bfs(int i,vector<vector<int>>& adj,vector<bool>&visit){
        queue<pair<int ,int> >q;
        visit[i]=1;
        q.push({i,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int j : adj[node]){
                if(j==parent) continue;
                if(visit[j]==1) return true;
                visit[j]=1;
                q.push({j,node});
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<bool>visit(v,0);
        for(int i=0;i<v;i++){
            if(!visit[i] && cycledetect_bfs(i,adj,visit)) return true;
        }
        return false;
    }
};

int main() {
    // Number of vertices and edges
    int vertices = 5;
    vector<vector<int>> adj(vertices);

    // Adding edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 4};
    adj[4] = {2, 3};

    Solution sol;
    if (sol.isCycle(adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}

