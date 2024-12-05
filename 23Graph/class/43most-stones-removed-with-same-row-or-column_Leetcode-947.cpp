/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {//create a not a graph
public:
    int vis[1010];
    void dfs(int node,vector<vector<int>>& stones){
        vis[node]=1;
        for(int i=0;i<stones.size();i++){
            if(!vis[i] and (stones[i][0]==stones[node][0] or stones[i][1]==stones[node][1])){
                dfs(i,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        memset(vis,0, sizeof(vis));
        int cc=0;
        for(int i=0;i<stones.size();i++){
            if(!vis[i]){
                cc++;
                dfs(i,stones);
            }
        }
        return (stones.size()-cc);
    }
};

class Solution {//create a graph 
public:
    vector<list<int>> graph;
    
    void dfs(int node, vector<int>& vis) {
        vis[node] = 1;
        for (auto neighbour : graph[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        graph.resize(n);
        vector<int> vis(n, 0);

        // Build the graph: connect nodes if they share a row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        // Count connected components
        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cc++;
                dfs(i, vis);
            }
        }
        return n - cc; // Maximum stones removed = total stones - connected components
    }
};



int main() {
    Solution solution;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 2}, {2, 3}};
    
    int result = solution.removeStones(stones);
    cout << "Maximum stones that can be removed: " << result << endl;

    return 0;
}