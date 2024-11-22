/*
code by Subrata Mondal
problem link :https://leetcode.com/problems/shortest-bridge/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public: 
    queue<pair<int,int>>q;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid,int i,int j,set<pair<int,int>>&visit){
        if(i<0 || j <0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0||visit.find({i,j})!=visit.end()) return;
        visit.insert({i,j});
        for(int d=0;d<4;d++){
            int nr=i+dir[d][0];
            int nc=j+dir[d][1];
            dfs(grid,nr,nc,visit);
        }
    }
    int bfs(vector<vector<int>>& grid,set<pair<int,int>>&visit){
        for(auto &it :visit) q.push(it);
        int level=0;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                auto cell=q.front();
                q.pop();
                int i=cell.first;
                int j=cell.second;
                for(int d=0;d<4;d++){
                    int nr=i+dir[d][0];
                    int nc=j+dir[d][1];
                    if(nr>=0 && nc >=0 && nr<grid.size() && nc<grid[0].size()&&visit.find({nr,nc})==visit.end()){
                        if(grid[nr][nc]==1) {//second island
                            return level;
                        }
                        visit.insert({nr,nc});
                        q.push({nr,nc});
                    }
                } 
            }
            level++;  
        }
        return level;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        set<pair<int,int>>visit;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,visit);
                    return bfs(grid,visit);
                }
            }
        }
        return -1;
    }
};

int main() {
    // Example test case
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    
    Solution solution;
    int result = solution.shortestBridge(grid);
    cout << "Shortest bridge length: " << result << endl;

    return 0;
}