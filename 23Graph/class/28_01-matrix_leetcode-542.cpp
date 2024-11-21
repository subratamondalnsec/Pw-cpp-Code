/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/01-matrix/description/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<int,int> >q;
        vector<vector<int>>m(r,vector<int>(c,INT_MAX));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    m[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int i=cell.first;
            int j=cell.second;
            for(int d=0;d<4;d++){
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];
                if(nr<0 || nc<0 || nr>=r || nc>=c) continue;
                if(mat[nr][nc]==0) continue;
                if (m[nr][nc] > m[i][j] + 1) {
                    m[nr][nc] = m[i][j] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return m;
    }
};

int main() {
    // Example test case
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    Solution solution;
    vector<vector<int>> result = solution.updateMatrix(mat);

    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}