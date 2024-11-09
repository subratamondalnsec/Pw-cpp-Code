
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<vector<int>>& adj, vector<int>&ans,vector<bool>&visit){
        ans.push_back(node);
        visit[node]=1;
        for(int j=0;j<adj[node].size();j++){
            if(!visit[adj[node][j]])  dfs(adj[node][j],adj,ans,visit);
        }
        
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<bool>visit(v,0);
        vector<int>ans;
        dfs(0,adj,ans,visit);
        return ans;
    }
};


int main() {
    // Create a Solution object
    Solution solution;

    // Define the adjacency list for the graph
    // Example graph with 4 nodes (0 to 3)
    vector<vector<int>> adj = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 3},    // Node 1 is connected to nodes 0 and 3
        {0, 3},    // Node 2 is connected to nodes 0 and 3
        {1, 2}     // Node 3 is connected to nodes 1 and 2
    };

    // Call dfsOfGraph method
    vector<int> dfsTraversal = solution.dfsOfGraph(adj);

    // Output the DFS traversal
    cout << "DFS Traversal of the Graph: ";
    for (int node : dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
