/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/coloring-a-border/
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<pair<int,int> >internal_col;
    void dfs(vector<vector<int> >& grid,int r,int c,int newcolor,int orginal_color){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=orginal_color) return ;
        grid[r][c]=-newcolor;
        dfs(grid,r+1,c,newcolor,orginal_color), dfs(grid,r-1,c,newcolor,orginal_color), dfs(grid,r,c+1,newcolor,orginal_color), dfs(grid,r,c-1,newcolor,orginal_color);
        if( not (r==0 || c==0 || r==grid.size()-1 || c==grid[0].size()-1 || grid[r+1][c]!=-newcolor || grid[r-1][c]!=-newcolor|| grid[r][c+1]!=-newcolor|| grid[r][c-1]!=-newcolor)) {
            internal_col.push_back({r,c});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color){
        int orginal_color=grid[row][col];
        if(orginal_color==color) return grid;
        dfs(grid,row,col,color,orginal_color);
        for(int i=0;i<internal_col.size();i++){
            int ro=internal_col[i].first,co=internal_col[i].second;
            grid[ro][co]=orginal_color;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j]*=(-1);
            }
        }
        return grid;
    }
};

int main() {
    // Example input grid
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 2, 2},
        {1, 1, 1}
    };

    // Target row, column, and new color
    int row = 1, col = 1, color = 3;

    // Instantiate the Solution class
    Solution solution;

    // Call the colorBorder function
    vector<vector<int>> result = solution.colorBorder(grid, row, col, color);

    // Print the result
    cout << "Updated grid:" << endl;
    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}