/*
code by Subrata Mondal
problem link :https://leetcode.com/problems/surrounded-regions/description/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {//bfs
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<int > >visit(r,vector<int >(c,0));
        queue<pair<int,int> >q;
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                visit[i][0]=1;
                q.push({i,0});
            }
            if(board[i][c-1]=='O'){
                visit[i][c-1]=1;
                q.push({i,c-1});
            }
        }
        for(int j=0;j<c;j++){
            if(board[0][j]=='O'){
                visit[0][j]=1;
                q.push({0,j});
            }
            if(board[r-1][j]=='O'){
                visit[r-1][j]=1;
                q.push({r-1,j});
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
                if(board[nr][nc]=='X' || visit[nr][nc]==1) continue;
                visit[nr][nc]=1;
                q.push({nr,nc});
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(visit[i][j]==0) board[i][j]='X';
            }
        }
        return ;
    }
};

class Solution {//dfs
private:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board){
        visited[row][col]=1;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+dir[i][0];
            int ncol=col+dir[i][1];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, visited, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && visited[i][0]==0){
                dfs(i, 0, visited, board);
            }
            if(board[i][m-1]=='O' && visited[i][m-1]==0){
                dfs(i, m-1, visited, board);
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && visited[0][j]==0){
                dfs(0, j, visited, board);
            }
            if(board[n-1][j]=='O' && visited[n-1][j]==0){
                dfs(n-1, j, visited, board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};


int main() {
    Solution solution;

    // Input board
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original Board:" << endl;
    for (auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // Call solve function
    solution.solve(board);

    // Output the modified board
    cout << "\nModified Board:" << endl;
    for (auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}