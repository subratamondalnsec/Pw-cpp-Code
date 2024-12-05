/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/course-schedule/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution { //same as 37
public:
    vector<list<int> > graph;
    int v; // no of vertices
    void add_edge(int a, int b) {
        graph[a].push_back(b); // a->b
    }
    vector<int>result;
    void topoBFS() {
        // Kahn algo
        vector<int> indegree(v, 0);
        for(int i = 0 ; i < v; i++){
            for(auto neighbour : graph[i]){
                // i ---> neighbour
                indegree[neighbour]++;
            }
        }
        queue<int> qu;
        unordered_set<int> vis;
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                qu.push(i);
                vis.insert(i);
            }
        }
        while(not qu.empty()){
            int node = qu.front();
            result.push_back(node);
            qu.pop();
            for(auto neighbour : graph[node]){
                if(not vis.count(neighbour)) {
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        qu.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
        }
    } 

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         v=numCourses;
        int e=prerequisites.size();
        graph.resize(v, list<int> ());
        while(e--) {
            int x=prerequisites[e][1], y=prerequisites[e][0];
            add_edge(x, y);//directed 
        }
        topoBFS();
        return (result.size() == v);
    }
};


class Solution {// same but different
public:
    vector<int>topo(int v,vector<vector<int>>& prerequisites){
        vector<int>graph[v];
        vector<int> indegre(v);
       for(auto i:prerequisites){
        graph[i[1]].push_back(i[0]);
        indegre[i[0]]++;
       }
       queue<int>q;
       for(int i=0;i<v;i++){
           if(indegre[i]==0)q.push(i);
       }
       vector<int>ans;
       while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbour:graph[node]){
              indegre[neighbour]--;
              if(indegre[neighbour]==0){
                    q.push(neighbour);
                }
            }
       }
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans=topo(numCourses,prerequisites);
        return (ans.size()==numCourses);
    }
};

int main() {
    Solution solution;

    // Define the number of courses and prerequisites
    int numCourses = 4; // Example: 4 courses
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 1}, {3, 2} // Example prerequisites
    };

    // Check if it's possible to finish all courses
    bool result = solution.canFinish(numCourses, prerequisites);

    // Output the result
    if (result) {
        cout << "All courses can be finished!" << endl;
    } else {
        cout << "It's impossible to finish all courses!" << endl;
    }

    return 0;
}