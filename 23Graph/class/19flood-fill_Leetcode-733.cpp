/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/flood-fill/
*/
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int initialcolor ,int color){
        if(sr>=image.size() || sc>=image[0].size() ||sr<0 || sc<0) return ;
        if(initialcolor!=image[sr][sc]) return ;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,initialcolor,color);//up
        dfs(image,sr,sc-1,initialcolor,color);//left
        dfs(image,sr-1,sc,initialcolor,color);//down
        dfs(image,sr,sc+1,initialcolor,color);//right

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc], color);
        return image;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    // Print the result
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}
