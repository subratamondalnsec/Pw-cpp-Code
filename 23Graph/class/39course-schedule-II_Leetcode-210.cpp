/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/course-schedule-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {//same as 37
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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        v=numCourses;
        int e=prerequisites.size();
        graph.resize(v, list<int> ());
        while(e--) {
            int x=prerequisites[e][1], y=prerequisites[e][0];
            add_edge(x, y);//directed 
        }
        topoBFS();
        return (result.size() == v) ? result :vector<int>{};
    }
};

class Solution { //same but different
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans=topo(numCourses,prerequisites);
        return (ans.size()==numCourses) ? ans : vector<int>{} ;
    }
};



int main() {
    Solution solution;

    // Define the number of courses and prerequisites
    int numCourses = 4; // Example: 4 courses
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 1}, {3, 2} // Example prerequisites
    };

    // Get the order of courses
    vector<int> result = solution.findOrder(numCourses, prerequisites);

    // Print the result
    if (result.empty()) {
        cout << "It's impossible to finish all courses!" << endl;
    } else {
        cout << "Order to finish courses: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}