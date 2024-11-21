/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/number-of-islands/
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{//bfs
public:
    int numIslands(vector<vector<char>> &grid){
        int noofisland = 0;
        queue<pair<int,int> >q;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '0') continue;
                noofisland++;//grid[i][j] == '1'
                q.push({i,j});
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    q.pop();
                    if(r-1>=0 && grid[r-1][c]=='1'){
                        q.push({r-1,c});
                        grid[r-1][c]='0';
                    }
                    if(c-1>=0 && grid[r][c-1]=='1'){
                        q.push({r,c-1});
                        grid[r][c-1] ='0';
                    }
                    if(r+1<grid.size() && grid[r+1][c]=='1'){
                        q.push({r+1,c});
                        grid[r+1][c]='0';
                    }
                    if(c+1<grid[0].size() && grid[r][c+1]=='1'){
                        q.push({r,c+1});
                        grid[r][c+1]='0';
                    }
                }
            }
        }
        return noofisland;
    }
};

class Solution{ //dfs
public:
    void dfs(vector<vector<char>> &grid, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >=grid[0].size())return;
        if (grid[i][j] == '0') return;
        if (grid[i][j] == '1'){
            grid[i][j] = '0';
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
        }
    }
    int numIslands(vector<vector<char>> &grid){
        int noofisland = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    noofisland++;
                    dfs(grid, i, j);
                }
            }
        }
        return noofisland;
    }
    
};


int main() {
    // Create a grid for testing
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Instantiate the Solution class
    Solution solution;

    // Call the numIslands function and print the result
    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}