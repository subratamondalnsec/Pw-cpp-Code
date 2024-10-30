#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>>dp;
    // int f(string& a, string& b, int idxA, int idxB){
    //     if (idxA == a.size() || idxB == b.size()) return 0;
    //     if(dp[idxA][idxB]!=-1) return dp[idxA][idxB];
    //     if (a[idxA] == b[idxB]) return dp[idxA][idxB]= 1 + f(a, b, idxA + 1, idxB + 1);
    //     else return dp[idxA][idxB]= max(f(a, b, idxA + 1, idxB),f(a, b, idxA, idxB + 1));
    // }
    int f(string& a, string& b, int idxA, int idxB){
        if (idxA < 0 || idxB < 0) return 0;
        if(dp[idxA][idxB]!=-1) return dp[idxA][idxB];
        if (a[idxA] == b[idxB]) return dp[idxA][idxB]=1 + f(a, b, idxA - 1, idxB - 1);
        else return dp[idxA][idxB]= max(f(a, b, idxA - 1, idxB),f(a, b, idxA, idxB - 1));
    }
    int minInsertions(string a) {
        string b=a;
        reverse(b.begin(),b.end());
        dp.resize(a.size()+4,vector<int>(b.size()+4,-1));
        //return f(a, b, 0, 0);
        return a.size() - f(a, b, a.size()-1,  b.size()-1);
    }
};

class Solution {
public:
    vector<vector<int>>dp;
    int minInsertions(string a) {
        string b=a;
        reverse(b.begin(),b.end());
        int n=a.size();
        int m=b.size();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
            }
        }
        return n- dp[n][m];
    }
};

int main(){
    Solution sol;
    string a;
    cout<<"Enter a string : ";
    cin>>a;
    int ans=sol.minInsertions(a);
    cout<<"The minimum number of words add string to make string palindrome is : "<<ans;
}