/*
code by Subrata Mondal
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    void dfs(int node,vector<vector<int>>& adj,vector<bool>&visit,stack<int>&s){
        visit[node]=true;
        for(auto nei : adj[node]){
            if(!visit[nei]) dfs(nei,adj,visit,s);
        }
        s.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>visit(n,false);
        stack<int>s;
        for(int i=0;i<n;i++){
            if(!visit[i]) dfs(i,adj,visit,s);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main() {
    // Create a directed graph as an adjacency list.
    // Example graph: 5 vertices (0 to 4)
    vector<vector<int>> adj = {
        {1, 2}, // Node 0 points to 1 and 2
        {3},    // Node 1 points to 3
        {3, 4}, // Node 2 points to 3 and 4
        {},     // Node 3 points to no one
        {}      // Node 4 points to no one
    };

    // Create an instance of the Solution class
    Solution sol;
    // Get the topological sort order
    vector<int> topoOrder = sol.topologicalSort(adj);

    // Print the topological order
    cout << "Topological Sort Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}