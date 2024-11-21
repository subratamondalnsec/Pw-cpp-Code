/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/pacific-atlantic-water-flow/
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int rows;
    int cols;
    vector<vector<int>>h;

    vector<vector<bool>>bfs(queue<pair<int,int> >& q){
        vector<vector<bool>>visit(rows,vector<bool>(cols,false));
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;
            visit[i][j]=true;
            for(int d=0;d<4;d++){
                int newrow=i+dir[d][0];
                int newcol=j+dir[d][1];
                if(newrow<0 || newrow>=rows || newcol <0 || newcol>=cols) continue;
                if(visit[newrow][newcol]) continue;
                if(h[newrow][newcol] < h[i][j]) continue;
                q.push({newrow,newcol});
            }
        }
        return visit;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        h=heights;
        queue<pair<int,int> >Pacific;
        queue<pair<int,int> >Atlantic;
        for(int i=0;i<rows;i++){
            Pacific.push({i,0});
            Atlantic.push({i,cols-1});
        }
        for(int i=1;i<cols;i++){
            Pacific.push({0,i});
        }
        for(int i=0;i<cols-1;i++){
            Atlantic.push({rows-1,i});
        }
        vector<vector<bool> >PacificBfs=bfs(Pacific);
        vector<vector<bool> >AtlanticBfs=bfs(Atlantic);
        vector<vector<int> >result;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(PacificBfs[i][j] && AtlanticBfs[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};

int main() {
    // Test case grid
    vector<vector<int>> heights = {
        {1, 1},
        {1, 1},
        {1, 1}
    };

    // Instantiate the Solution class
    Solution solution;

    // Call the function
    vector<vector<int>> result = solution.pacificAtlantic(heights);

    // Print the result
    cout << "Cells that can flow to both oceans:" << endl;
    for (const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;

    return 0;
}