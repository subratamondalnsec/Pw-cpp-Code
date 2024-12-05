/*code by Subrata Mondal
problem link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {//dfs
  public:
    // Function to detect cycle in a directed graph.
    bool detect(int node,vector<vector<int>>& adj,vector<bool>&vis,vector<bool>&path){
        vis[node]=1;
        path[node]=1;
        for(auto nei : adj[node]){
            if(path[nei]) return 1;
            if(vis[nei]) continue;
            if(detect(nei,adj,vis,path)) return 1;
        }
        path[node]=0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
       vector<bool>vis(V,false);
       vector<bool>path(V,false);
       for(int i=0;i<V;i++){
           if(!vis[i] && detect(i,adj,vis,path)){
               return 1;
            } 
        }
       return 0;
    }
};


class Solution {//bfs
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
       vector<int>indegree(V,0);
       for(auto v : adj){
           for( auto e : v){
               indegree[e]++;
           }
       }
       queue<int>q;
       unordered_set<int>s;
       for(int i=0;i<indegree.size();i++){
           if(indegree[i]==0){
               q.push(i);
               s.insert(i);
           }
       }
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto nei : adj[node]){
               if(!s.count(nei)){
                   indegree[nei]--;
                   if(indegree[nei]==0){
                        q.push(nei);
                        s.insert(nei);
                   }
                   
               }
           }
       }
       
       return V!=s.size();
    }
};


int main(){
    Solution sol;

    // Example 1: Graph with a cycle.
    // Graph: 0 --> 1 --> 2 --> 0 (Cycle)
    vector<vector<int>> adj1 = {
        {1},    // Node 0 points to 1.
        {2},    // Node 1 points to 2.
        {0}     // Node 2 points back to 0 (cycle).
    };
    int V1 = adj1.size();
    cout << "Graph 1 has a cycle: " << (sol.isCyclic(V1, adj1) ? "Yes" : "No") << endl;

    // Example 2: Graph without a cycle.
    // Graph: 0 --> 1 --> 2
    vector<vector<int>> adj2 = {
        {1},    // Node 0 points to 1.
        {2},    // Node 1 points to 2.
        {}      // Node 2 has no outgoing edges.
    };
    int V2 = adj2.size();
    cout << "Graph 2 has a cycle: " << (sol.isCyclic(V2, adj2) ? "Yes" : "No") << endl;

    return 0;
}

