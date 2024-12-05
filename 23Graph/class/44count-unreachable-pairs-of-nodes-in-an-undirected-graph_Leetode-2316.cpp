/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<list<int> > graph;
    vector<int>cc;
    vector<int>vis;
    void dfs(int node,int &count){
        vis[node]=1;
        count++;
        for(auto neighbour : graph[node]){
            if(!vis[neighbour] ){
                dfs(neighbour,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vis.resize(n,0);
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int count=0;
                dfs(i,count);
                cc.push_back(count);
            }
        }
        if(cc.size()==1) return 0;
        int total=n;
        long long ans=0;
        for(int i=0;i<cc.size();i++){
            ans+=(long long) (total-cc[i])*cc[i];
            total-=cc[i];
        }
        return ans;
    }
};


int main() {
    Solution solution;
    
    // Example Input
    int n = 7; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1}, 
        {0, 2}, 
        {3, 4}, 
        {5, 6}
    };
    
    // Calculate the number of unreachable pairs
    long long result = solution.countPairs(n, edges);

    // Output the result
    cout << "Number of unreachable pairs: " << result << endl;

    return 0;
}