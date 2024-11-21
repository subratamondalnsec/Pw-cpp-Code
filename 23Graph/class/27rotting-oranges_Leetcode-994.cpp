/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/rotting-oranges/
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int fo=0;
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) fo++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        q.push({-1,-1});
        int min=0;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            if(cell.first==-1 && cell.second==-1){
                min++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                else{
                    break;
                } 
            }
            else{
                int i=cell.first;
                int j=cell.second;
                for(int d=0;d<4;d++){
                    int nr=i+dir[d][0];
                    int nc=j+dir[d][1];
                    if(nr<0 || nc<0 || nr>=r || nc>=c) continue;
                    if(grid[nr][nc]==2 || grid[nr][nc]==0) continue;
                    fo--;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        }
        return (fo==0)? min-1 : -1;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test input grid
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Call the orangesRotting function
    int result = solution.orangesRotting(grid);

    // Print the result
    cout << "Minimum time required to rot all oranges: " << result << endl;

    return 0;
}