#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int v=adj.size();
        queue<int>q;
        q.push(0);
        vector<bool>visit(v,0);
        visit[0]=1;
        vector<int>ans;
        int node;
        while(!q.empty()){
            node=q.front();
            q.pop();
            ans.push_back(node);
            for(int j=0;j<adj[node].size();j++){
                if(!visit[adj[node][j]]){
                    visit[adj[node][j]]=1;
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};


int main() {
    // Create a Solution object
    Solution solution;

    // Define the adjacency list for the graph
    // Example graph with 5 nodes (0 to 4)
    vector<vector<int>> adj = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 3, 4}, // Node 1 is connected to nodes 0, 3, and 4
        {0, 4},    // Node 2 is connected to nodes 0 and 4
        {1},       // Node 3 is connected to node 1
        {1, 2}     // Node 4 is connected to nodes 1 and 2
    };

    // Call bfsOfGraph method
    vector<int> bfsTraversal = solution.bfsOfGraph(adj);

    // Output the BFS traversal
    cout << "BFS Traversal of the Graph: ";
    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
